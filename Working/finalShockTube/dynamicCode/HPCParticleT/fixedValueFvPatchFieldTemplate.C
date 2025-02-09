/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "fixedValueFvPatchFieldTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
//{{{ begin codeInclude

//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    // dynamicCode:
    // SHA1 = dc7a18ddce2418b0425a037ff6effb5f05c5ecb6
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void HPCParticleT_dc7a18ddce2418b0425a037ff6effb5f05c5ecb6(bool load)
    {
        if (load)
        {
            // code that can be explicitly executed after loading
        }
        else
        {
            // code that can be explicitly executed before unloading
        }
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

makeRemovablePatchTypeField
(
    fvPatchScalarField,
    HPCParticleTFixedValueFvPatchScalarField
);


const char* const HPCParticleTFixedValueFvPatchScalarField::SHA1sum =
    "dc7a18ddce2418b0425a037ff6effb5f05c5ecb6";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

HPCParticleTFixedValueFvPatchScalarField::
HPCParticleTFixedValueFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchField<scalar>(p, iF)
{
    if (false)
    {
        Info<<"construct HPCParticleT sha1: dc7a18ddce2418b0425a037ff6effb5f05c5ecb6"
            " from patch/DimensionedField\n";
    }
}


HPCParticleTFixedValueFvPatchScalarField::
HPCParticleTFixedValueFvPatchScalarField
(
    const HPCParticleTFixedValueFvPatchScalarField& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchField<scalar>(ptf, p, iF, mapper)
{
    if (false)
    {
        Info<<"construct HPCParticleT sha1: dc7a18ddce2418b0425a037ff6effb5f05c5ecb6"
            " from patch/DimensionedField/mapper\n";
    }
}


HPCParticleTFixedValueFvPatchScalarField::
HPCParticleTFixedValueFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchField<scalar>(p, iF, dict)
{
    if (false)
    {
        Info<<"construct HPCParticleT sha1: dc7a18ddce2418b0425a037ff6effb5f05c5ecb6"
            " from patch/dictionary\n";
    }
}


HPCParticleTFixedValueFvPatchScalarField::
HPCParticleTFixedValueFvPatchScalarField
(
    const HPCParticleTFixedValueFvPatchScalarField& ptf
)
:
    fixedValueFvPatchField<scalar>(ptf)
{
    if (false)
    {
        Info<<"construct HPCParticleT sha1: dc7a18ddce2418b0425a037ff6effb5f05c5ecb6"
            " as copy\n";
    }
}


HPCParticleTFixedValueFvPatchScalarField::
HPCParticleTFixedValueFvPatchScalarField
(
    const HPCParticleTFixedValueFvPatchScalarField& ptf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchField<scalar>(ptf, iF)
{
    if (false)
    {
        Info<<"construct HPCParticleT sha1: dc7a18ddce2418b0425a037ff6effb5f05c5ecb6 "
            "as copy/DimensionedField\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

HPCParticleTFixedValueFvPatchScalarField::
~HPCParticleTFixedValueFvPatchScalarField()
{
    if (false)
    {
        Info<<"destroy HPCParticleT sha1: dc7a18ddce2418b0425a037ff6effb5f05c5ecb6\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void HPCParticleTFixedValueFvPatchScalarField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        Info<<"updateCoeffs HPCParticleT sha1: dc7a18ddce2418b0425a037ff6effb5f05c5ecb6\n";
    }

//{{{ begin code
    #line 20 "/home/anthonygay1812/OpenFOAM/Working/finalShockTube/system/particle/codeDict.HPCParticleT"
const fvMesh& fluidMeshRef = db().parent().lookupObject<fvMesh>("fluid");
    label fluidBoundPatchId=fluidMeshRef.boundaryMesh().findPatchID("fluidBound");
    Info<<"HPCParticleT Has been accessed" <<nl;
    const volScalarField& TFluid = fluidMeshRef.lookupObject<volScalarField>("T");     

    operator==(TFluid.boundaryField()[fluidBoundPatchId][0]);
//}}} end code

    this->fixedValueFvPatchField<scalar>::updateCoeffs();
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

