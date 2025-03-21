#include <TH1D.h>
#include <TRandom3.h>
#include <TMath.h>

#include <ctime>

void solve()
{
    TRandom3 rnd(0);
    
    // Create, Fill and Draw Histogram
    TH1D* hist = new TH1D("hist", "Hist for 3 task", 100, -50, 50);

    // Fill Histogram
    
    //for (int i = 0; i < 100000; i++) hist->Fill(100*rnd.Rndm() - 50);
    hist->Draw("E");
}
