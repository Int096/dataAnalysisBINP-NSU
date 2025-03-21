#include "TFitResultPtr.h"
#include <TFitResult.h>
#include <TH1D.h>
#include <TF1.h>
#include <TCanvas.h>

void solve(Int_t N = 1000)
{
    // Create Canvas
    const Int_t w = 600, h = 800;
    TCanvas c("c", "Task 4", w, h);

    // Create Histograms 
    TH1F hist("hist", "", 100, -2, 2);
    TF1 fitFunc("fitFunc", "[0] + [1]*x + [2]*x*x", -2, 2);

    hist.FillRandom("gausn", N);
    TFitResultPtr r = hist.Fit("fitFunc", "LS", "ep");

    std::cout << std::endl << std::endl
        << "p = " << r->Prob()
        << " chi2 = " << r->Chi2()
        << " ndf = " << r->Ndf()
    << std::endl;


    TF1 chi2Func("chi2Func", "10000*ROOT::TMath::chisquared_pdf(x,97)", 50, 300);
}
