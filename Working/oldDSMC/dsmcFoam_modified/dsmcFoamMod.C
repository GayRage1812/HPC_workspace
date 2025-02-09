/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2018 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    dsmcFoamV1

Description
    Direct simulation Monte Carlo (DSMC) solver for, transient, multi-species
    flows. Modified by Anthony Gay to run shocktube test case.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "dsmcCloud.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #define NO_CONTROL
    #include "postProcess.H"
    
    #include "setRootCaseLists.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createFields.H"

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nStarting time loop\n" << endl;

    while (runTime.loop())
    {
        Info<< "Time = " << runTime.timeName() << nl << endl;

        dsmc.evolve();
        //Info<< "Evolve function was successful."<<  endl;
        dsmc.info();
        //Info<< "Info function was successful."<<  endl;

        runTime.write();

         dimensionedScalar simTime=runTime.time();
         dimensionedScalar simDt=runTime.deltaT();
         dimensionedScalar endTime=runTime.endTime();
         scalar remainIts=(endTime.value()/simDt.value())-(simTime.value()/simDt.value());
         scalar timePerIt=runTime.elapsedCpuTime()/(simTime.value()/simDt.value());

        Info<< nl << "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << "  Iterations: " << (simTime.value()/simDt.value()) << "/" << (endTime.value()/simDt.value())
            << "  Projected time to finish: " << (remainIts*timePerIt)/60 << " min"
            << endl;
    }

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
