/*
Copyright (C) 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Theater Square in the capital city of Berland has a rectangular shape
with the size n × m meters. On the occasion of the city's anniversary,
a decision was taken to pave the Square with square granite flagstones.
Each flagstone is of the size a × a.

What is the least number of flagstones needed to pave the Square? It's
allowed to cover the surface larger than the Theatre Square, but the
Square has to be covered. It's not allowed to break the flagstones.
The sides of flagstones should be parallel to the sides of the Square.
*/
#include <cstdio>
#include <cmath>

int main() {
  double m, n, a;
  scanf("%lf %lf %lf", &m, &n, &a);
  printf("%.0lf", ceil(m/a)*ceil(n/a));
  return 0;
}
