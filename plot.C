#include "../../style.h"
#include "published.h"

void initHist(TH2D* h);

void plot(string fname, vector<string> grs, vector<string> l, pair<double, double> xrange = make_pair<double, double>(1, 99), pair<double, double> yrange = make_pair<double, double>(0, 0.15))
{
	TFile * f = new TFile(fname.c_str());
	vector<TGraphErrors*> vgr;
	for ( auto t : grs ) {
		cout << t << endl;
		vgr.push_back( (TGraphErrors*) f->Get(t.c_str()) ) ;
	}

	TCanvas * cC = MakeCanvas("cC", "cC", 600, 500);
	TH2D * hframe = new TH2D("hframe", ";Centrality;v_{n}{m}", 1, xrange.first, xrange.second, 1, yrange.first, yrange.second);
	initHist(hframe);

	TLegend * legC = new TLegend(0.6, 0.25, 0.9, 0.4);
	legC->SetFillColor(kWhite);
	legC->SetTextFont(42);
	legC->SetTextSize(0.06);
	legC->SetBorderSize(0);


	hframe->Draw();
	auto lit = l.begin();
	for ( auto t : vgr ) {
		t->Draw("psame");
		legC->AddEntry(t, lit->c_str(), "p");
		lit++;
	}
	legC->Draw();

	TLatex latexB;
	latexB.SetTextFont(43);
	latexB.SetTextSize(24);
	latexB.SetTextAlign(13);
	TLatex latexS;
	latexS.SetTextFont(43);
	latexS.SetTextSize(22);
	latexS.SetTextAlign(13);

	latexS.DrawLatexNDC(0.30, 0.92, "#bf{CMS Preliminary}");
	latexS.DrawLatexNDC(0.30, 0.87, "0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4");

}

void initHist(TH2D * h)
{
	h->GetXaxis()->CenterTitle();
	h->GetXaxis()->SetTitleOffset(1.3);

	h->GetYaxis()->CenterTitle();
	h->GetYaxis()->SetTitleOffset(1.3);

//	h->GetXaxis()->SetLabelFont(43);
//	h->GetXaxis()->SetLabelSize(20);
//	h->GetXaxis()->SetLabelOffset(0.02);
//	h->GetXaxis()->SetTitleFont(43);
//	h->GetXaxis()->SetTitleSize(22);
//	h->GetXaxis()->SetNdivisions(505);
//	h->GetXaxis()->SetTickLength(0.03);
//	h->GetXaxis()->SetTitleOffset(3);
//
//	h->GetYaxis()->SetLabelFont(43);
//	h->GetYaxis()->SetLabelSize(20);
//	h->GetYaxis()->SetLabelOffset(0.02);
//	h->GetYaxis()->SetTitleFont(43);
//	h->GetYaxis()->SetTitleSize(26);
//	h->GetYaxis()->CenterTitle();
//	h->GetYaxis()->SetNdivisions(505);
//	h->GetYaxis()->SetTickLength(0.03);
//	h->GetYaxis()->SetTitleOffset(1.5);
}
