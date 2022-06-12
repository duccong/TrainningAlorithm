#ifndef PART2_H
#define PART2_H


class Part2
{
public:
    Part2();

    void ChinhHopLap(int _n = -1, int _k = -1);
    void ChinhHop(int _n = -1, int _k = -1);  // Arrangement
    void ToHop(int _n = -1, int _k = -1);    // Combine
    void HoanVi(int _n = -1);// Permutation
    void swap(int *a, int i1, int i2);
    void dayNhiPhan0101(); // Wrong!!
};

#endif // PART2_H
