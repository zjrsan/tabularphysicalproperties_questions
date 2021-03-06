/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2018 Yuusha and tilasoldo
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of tilasoldo and Yuusha contribution to OpenFOAM.
    It is based on chriss85 contribution for OpenFOAM 2.3.x.

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

#include "tabularEOS.H"
#include "IOstreams.H"

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

template<class Specie>
Foam::tabularEOS<Specie>::tabularEOS(Istream& is)
:
    Specie(is)
{
    is.check("tabularEOS<Specie>::tabularEOS(Istream& is)");
    densityTable = extrapolation2DTable<scalar>("constant/densityTable");
    densityTable.outOfBounds(extrapolation2DTable<scalar>::EXTRAPOLATE);
}


template<class Specie>
Foam::tabularEOS<Specie>::tabularEOS(const dictionary& dict)
:
    Specie(dict),
    densityTable(dict.subDict("equationOfState"))
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Specie>
void Foam::tabularEOS<Specie>::write(Ostream& os) const
{
    return;
}


// * * * * * * * * * * * * * * * Ostream Operator  * * * * * * * * * * * * * //

template<class Specie>
Foam::Ostream& Foam::operator<<(Ostream& os, const tabularEOS<Specie>& ico)
{
    os  << static_cast<const Specie&>(ico);
    os.check("Ostream& operator<<(Ostream& os, const tabularEOS<Specie>& ico)");
    return os;
}


// ************************************************************************* //
