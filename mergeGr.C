#include "label.h"
#include "noff.h"

typedef struct
{
	TGraphErrors * grCn;
	TGraphErrors * grVn;
	TGraphErrors * grC4;
	TGraphErrors * grV4;
} VnGraph;

void getGraph(TFile * f, VnGraph &gr, int n)
{
	gr.grCn = (TGraphErrors*) f->Get(Form("grCn%i", n));
	gr.grVn = (TGraphErrors*) f->Get(Form("grVn%i", n));

	gr.grC4 = (TGraphErrors*) f->Get(Form("grC4%i", n));
	gr.grV4 = (TGraphErrors*) f->Get(Form("grV4%i", n));
}

TGraphErrors* combineGr(TGraphErrors* gMB0, TGraphErrors* gHM0, TGraphErrors* gHM1, TGraphErrors* gHM7)
{
	double y[14], ey[14];
	for ( int i = 0; i < 6; i++ ) {
		y[i]  = gMB0->GetY() [i];
		ey[i] = gMB0->GetEY()[i];
	}
	for ( int i = 6; i < 8; i++ ) {
		y[i]  = gHM0->GetY() [i];
		ey[i] = gHM0->GetEY()[i];
	}
	for ( int i = 8; i < 10; i++ ) {
		y[i]  = gHM1->GetY() [i];
		ey[i] = gHM1->GetEY()[i];
	}
	for ( int i = 10; i < 14; i++ ) {
		y[i]  = gHM7->GetY() [i];
		ey[i] = gHM7->GetEY()[i];
	}
	TGraphErrors * ret = new TGraphErrors(14, CentPPbX4, y, 0, ey);
	ret->SetMarkerStyle(gMB0->GetMarkerStyle());
	ret->SetMarkerColor(gMB0->GetMarkerColor());
	ret->SetLineColor(gMB0->GetLineColor());
	return ret;
}

void mergeGr(int n = 2, int sMB = 15, int sHM0 = 1, int sHM1 = 2, int sHM7 = 8)
{
	TFile * fMB0 = new TFile(Form("%s/outGraph.root", ftxt[sMB]));
	TFile * fHM0 = new TFile(Form("%s/outGraph.root", ftxt[sHM0]));
	TFile * fHM1 = new TFile(Form("%s/outGraph.root", ftxt[sHM1]));
	TFile * fHM7 = new TFile(Form("%s/outGraph.root", ftxt[sHM7]));

	VnGraph grMB0;
	VnGraph grHM0;
	VnGraph grHM1;
	VnGraph grHM7;

	getGraph(fMB0, grMB0, n);
	getGraph(fHM0, grHM0, n);
	getGraph(fHM1, grHM1, n);
	getGraph(fHM7, grHM7, n);

	TGraphErrors * grCn = combineGr(grMB0.grCn, grHM0.grCn, grHM1.grCn, grHM7.grCn);
	TGraphErrors * grVn = combineGr(grMB0.grVn, grHM0.grVn, grHM1.grVn, grHM7.grVn);
	TGraphErrors * grC4 = combineGr(grMB0.grC4, grHM0.grC4, grHM1.grC4, grHM7.grC4);
	TGraphErrors * grV4 = combineGr(grMB0.grV4, grHM0.grV4, grHM1.grV4, grHM7.grV4);

	TFile * fsave = new TFile(Form("combined_%i_%i_%i_%i_%i.root", sMB, sHM0, sHM1, sHM7, n), "recreate");
	grCn->Write("grCn");
	grVn->Write("grVn");
	grC4->Write("grC4");
	grV4->Write("grV4");
}
