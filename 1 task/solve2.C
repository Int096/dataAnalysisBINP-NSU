#include <TCanvas.h>
#include <TF1.h>

void solve2(const Int_t N = 3)
{
    TCanvas* c = new TCanvas("c", "Part 2", 800, 600);
    
    TF1* gauss = new TF1("gauss", "TMath::Gaus(x, [0], [1], 1)", 70,120);
    TF1* poisson = new TF1("poisson", "TMath::Poisson(x, [0])", 70, 120);

    gauss->SetParameters(N, TMath::Sqrt(N));
    poisson->SetParameters(N);

    gauss->SetNpx(1000);
    poisson->SetNpx(1000);

    gauss->SetLineColor(kRed);
    poisson->SetLineColor(kBlue);

    gauss->SetTitle("Gaus(N, Sqrt(N)) vs Poisson(N)");

    gauss->Draw();
    poisson->Draw("SAME");

    c->SaveAs(Form("part 2/GaussVsPoisson_N-%d.png", N));
}
