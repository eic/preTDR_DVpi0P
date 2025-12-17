#include "ePIC_style.C"


//=====================
void plots_DVpi0P(bool save_plot = true,
                            bool add_epic_logo = false)
{
  // ===== Set the style =====
  gROOT -> ProcessLine("set_ePIC_style()");

  // ===== Histogram Files =====
  TFile *f = new TFile("../sim_data/output_5on41.root");

  // ===== Histograms =====
  TH2D *hGammaEtaVsEtaMC = (TH2D*)f->Get("hGammaEtaVsEtaMC");

  // ===== Draw histograms =====
  TCanvas *canvas = new TCanvas("canvas", "", 800, 600);
  canvas -> SetTitle("Plot DVpi0P");

  TLatex Text_ePIC;
  Text_ePIC.SetTextSize(0.05);
  Text_ePIC.SetTextFont(62);
  //Text_ePIC.DrawLatexNDC(.15,.88,"ePIC Performnace");  // performance plot
  //Text_ePIC.DrawLatexNDC(.15,.88,"ePIC Internal");  // for internal use only
  //Text_ePIC.DrawLatexNDC(.15,.88,"ePIC Preliminary"); // preliminary released version 
  //Text_ePIC.DrawLatexNDC(.15,.88,"ePIC Work in Progress"); // work in progress to be shown outside
  //Text_ePIC.DrawLatexNDC(.15,.88,"ePIC"); // final published version  
  
  canvas -> SetLogz(1);
  hGammaEtaVsEtaMC->SetStats(0);
  hGammaEtaVsEtaMC->GetXaxis()->CenterTitle(true);
  hGammaEtaVsEtaMC->GetYaxis()->CenterTitle(true);
  hGammaEtaVsEtaMC->Draw("COLZ");

  TLatex Text_com1;
  Text_com1.SetTextAlign(13);  //align at top
  Text_com1.DrawLatexNDC(.15,.85,"EpIC 1.1.6");
  Text_com1.DrawLatexNDC(.15,.8,"e+p DV#pi^{0}P 5#times41 GeV^{2}");
  Text_ePIC.DrawLatexNDC(.15,.88,"ePIC Performance 25.10.3");  // performance plot
  
  if(add_epic_logo)
    {
      // ===== Add ePIC logo to the figure if desired ======
      TImage *logo = TImage::Open("EPIC-logo_black_small.png");
      TPad *pad2 = new TPad("pad2", "Pad 2", 0.8, 0.8, 0.93, 0.93); // Create a new pad and then draw the image in it
      pad2->Draw(); 
      pad2->cd(); // Enter the new pad
      logo->Draw();
    }

  if(save_plot)
    {
      canvas -> SaveAs("../results/DVpi0P.pdf");
    }
}
