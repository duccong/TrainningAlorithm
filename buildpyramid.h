/*
  input: array of stones
  output: cost to cut of stones to make pyramids.
          Each step of pyramid will higher 1 more, start and end stone must be equal 1
  ex: [1 1 3 3 2 1] -> [0 1 2 3 2 1] -> cost = 2
0 1 2 3 2 3 -> Top at: 3 - high: 3  highest: 3 Cost: 2
2 3 4 4 3 3 -> Top at: 2 - high: 3  highest: 4 Cost: 10
0 0 0 1 9 10 -> Top at: 4 - high: 2  highest: 2 Cost: 16
1 1 3 3 2 1 -> Top at: 3 - high: 3  highest: 3 Cost: 2
1 1 1 1 1 ->  Top at anywhere - high: 1  highest: 1 Cost: 5
4 4 4 3 3 3 3 -> Top at: 3 - high: 3  highest: 3 Top at: 2 - high: 3  highest: 3 Cost: 15
0 5 2 0 0 0 0 ->Top at anywhere - high: 1  highest: 1 Cost: 6
1 2 3 2 1 5 4 -> Top at: 2 - high: 3  highest: 3 Cost: 9
1 5 6 3 2 9 0 -> Top at: 3 - high: 3  highest: 3 Cost: 17
1 2 3 4 5 6 7 -> Top at: 3 - high: 4  highest: 4 Cost: 12
Total time taken by CPU: 0.000102

*/
#ifndef BUILDPYRAMID_H
#define BUILDPYRAMID_H
#include "utils.h"

class BuildPyramid
{
public:
    BuildPyramid();
};

#endif // BUILDPYRAMID_H
