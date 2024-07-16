/**********************************************************************
 *
 * PostGIS - Spatial Types for PostgreSQL
 * http://postgis.net
 *
 * PostGIS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * PostGIS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PostGIS.  If not, see <http://www.gnu.org/licenses/>.
 *
 **********************************************************************
 *
 * Copyright 2009 Mark Cave-Ayland <mark.cave-ayland@siriusit.co.uk>
 * Copyright 2009-2017 Paul Ramsey <pramsey@cleverelephant.ca>
 * Copyright 2018 Darafei Praliaskouski <me@komzpa.net>
 *
 **********************************************************************/

/*****************************************************************************
 * BOX3D operators
 *****************************************************************************/

bool BOX3D_contains_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_contained_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_overlaps_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_same_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_left_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_overleft_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_right_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_overright_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_below_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_overbelow_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_above_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_overabove_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_front_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_overfront_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_back_internal(BOX3D *box1, BOX3D *box2);
bool BOX3D_overback_internal(BOX3D *box1, BOX3D *box2);
double BOX3D_distance_internal(BOX3D *box1, BOX3D *box2);

