#include <TH1D.h>
#include <TCanvas.h>

#include <iostream>

void solve()
{
    const Double_t w = 600, h = 800;

    // Create 1 part of Task
    TCanvas* c1 = new TCanvas("c1", "Part 1", h, w);

    TH1D* hist1 = new TH1D("hist1", "1 part of task", 500, -100, 100);
    hist1->FillRandom("pol0", 25000);
    hist1->Draw("E");

    std::vector<Int_t> binContents;
    for (Int_t i = 0; i < 500; i++) binContents.push_back(hist1->GetBinContent(i));

    std::cout << binContents.sum();
}
