#include "label.h"
#include "noff.h"

typedef struct
{
	TGraphErrors * grCn;
	TGraphErrors * grVn;
	TGraphErrors * grC4;
	TGraphErrors * grV4;
	TGraphErrors * grC6;
	TGraphErrors * grV6;
	TGraphErrors * grC8;
	TGraphErrors * grV8;
} VnGraph;

void getGraph(TFile * f, VnGraph &gr, int n)
{
	gr.grCn = (TGraphErrors*) f->Get(Form("grCn%i", n));
	gr.grVn = (TGraphErrors*) f->Get(Form("grVn%i", n));

	gr.grC4 = (TGraphErrors*) f->Get(Form("grC4%i", n));
	gr.grV4 = (TGraphErrors*) f->Get(Form("grV4%i", n));

	gr.grC6 = (TGraphErrors*) f->Get(Form("grC6%i", n));
	gr.grV6 = (TGraphErrors*) f->Get(Form("grV6%i", n));

	gr.grC8 = (TGraphErrors*) f->Get(Form("grC8%i", n));
	gr.grV8 = (TGraphErrors*) f->Get(Form("grV8%i", n));
}

TGraphErrors* combineGr(TGraphErrors* gMB0, TGraphErrors* gHM0, TGraphErrors* gHM1, TGraphErrors* gHM7)
{
	double y[20], ey[20];
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
	for ( int i = 10; i < gMB0->GetN(); i++ ) {
		y[i]  = gHM7->GetY() [i];
		ey[i] = gHM7->GetEY()[i];
	}
	TGraphErrors * ret = new TGraphErrors(gMB0->GetN(), CentPbPbX4, y, 0, ey);
	ret->SetMarkerStyle(gMB0->GetMarkerStyle());
	ret->SetMarkerColor(gMB0->GetMarkerColor());
	ret->SetLineColor(gMB0->GetLineColor());
	return ret;
}

void mergeGr(int n = 2, int sMB = 9, int sHM0 = 1, int sHM1 = 2, int sHM7 = 8)
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

	TGraphErrors * grC6 = combineGr(grMB0.grC6, grHM0.grC6, grHM1.grC6, grHM7.grC6);
	TGraphErrors * grV6 = combineGr(grMB0.grV6, grHM0.grV6, grHM1.grV6, grHM7.grV6);

	TGraphErrors * grC8 = combineGr(grMB0.grC8, grHM0.grC8, grHM1.grC8, grHM7.grC8);
	TGraphErrors * grV8 = combineGr(grMB0.grV8, grHM0.grV8, grHM1.grV8, grHM7.grV8);

	TFile * fsave = new TFile(Form("combined_%i_%i_%i_%i_%i.root", sMB, sHM0, sHM1, sHM7, n), "recreate");
	grCn->Write(Form("grC%in", n));
	grVn->Write(Form("grV%in", n));
	grC4->Write(Form("grC%i4", n));
	grV4->Write(Form("grV%i4", n));
	grC6->Write(Form("grC%i6", n));
	grV6->Write(Form("grV%i6", n));
	grC8->Write(Form("grC%i8", n));
	grV8->Write(Form("grV%i8", n));
}
