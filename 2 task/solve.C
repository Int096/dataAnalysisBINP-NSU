#include <TFitResultPtr.h>
#include <TFitResult.h>
#include <TH1D.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLatex.h>
#include <TLegend.h>

void solve(const Int_t N = 1000) 
{
    // Create canvas
    TCanvas* c = new TCanvas("c", "F-test", 800, 600);
    
    // Create histogram and function
    TH1D* hist = new TH1D("hist", Form("F-test for N = %d", N), 40, -100, 100);
    TF1 func("func", "[0] + [1]*(x/100.) + [2]*(x/100.)**2 + [3]*(x/100.)**3 + [4]*(x/100.)**4", -100, 100);
    func.SetParameters(10, -6, 3, 7, -3);

    hist->FillRandom("func", N);
    hist->Draw("E");

    // Polynoms
    TString pol = "[0]";
    std::vector<TFitResultPtr> fitResArr;

    TF1 fitFunc0("fitFunc0", pol, -100, 100);
    fitResArr.push_back(hist->Fit("fitFunc0", "+LS"));

    // Алгоритм подгонки
    Int_t i = 1;
    Double_t D = 0;
    do {
        pol = pol.Format(pol + " + [%i]*x**%i", i, i);
        TF1 fitFunc(Form("fitFunc%i", i), pol, -100, 100);
        fitResArr.push_back(hist->Fit(Form("fitFunc%i", i), "+LS"));
        D = -2 * (fitResArr.at(i)->MinFcnValue() - fitResArr.at(i-1)->MinFcnValue());
        i++;
    } while(D > 3.84);

    // Вывод результатов
    std::cout << std::endl << std::endl << "----------------" << std::endl
        << Form("Полиномы %d и %d степеней дают одинаковое качество подгонки", i, i-1) << std::endl 
        << Form("Тестовая статистика при этом равна D = %f", D) << std::endl
        << std::endl;

    // Добавление легенды
    TLatex latex;
    latex.SetNDC();
    latex.SetTextSize(0.03);
    latex.DrawLatex(0.15, 0.15, Form("D = %.2f; i = %d", D, i-1));

    c->SaveAs(Form("F-test_N-%d.png", N));
}
