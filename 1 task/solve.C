#include <TH1D.h>
#include <TF1.h>
#include <TCanvas.h>

#include <iostream>
#include <numeric>

void solve()
{
    TCanvas* c1 = new TCanvas("c1", "Part 1", 800, 600);

    TH1D* hist1 = new TH1D("hist1", "1 part of task", 500, -10, 10);
    hist1->FillRandom("pol0", 25000);
    hist1->Draw("E");

    TF1* meanFunc = new TF1("meanFunc", "50", -10, 10);
    meanFunc->Draw("SAME");
}
