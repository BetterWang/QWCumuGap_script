
void trimV24PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 30. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};

void trimC24PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 10. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};


void trimV26PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 100. or gr->GetX()[idx] > 310 ) gr->RemovePoint( idx );
		else idx++;
	}
};

void trimC26PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 100. or gr->GetX()[idx] > 310 ) gr->RemovePoint( idx );
		else idx++;
	}
};


void trimV28PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 100. or gr->GetX()[idx] > 310 ) gr->RemovePoint( idx );
		else idx++;
	}
};

void trimC28PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 100. or gr->GetX()[idx] > 310 ) gr->RemovePoint( idx );
		else idx++;
	}
};



void trimV34PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 150. or gr->GetX()[idx] > 310 ) gr->RemovePoint( idx );
		else idx++;
	}
};


void trimC34PA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 10. or gr->GetX()[idx] > 310 ) gr->RemovePoint( idx );
		else idx++;
	}
};

////////////////////////////////////////

void trimV24AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 30. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};

void trimC24AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 10. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};


void trimC26AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 50. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};


void trimV26AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 50. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};


void trimC28AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 60. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};


void trimV28AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 60. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};





void trimV34AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 150. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};

void trimC34AA(TGraphErrors* gr) {
	int idx = 0;
	while ( idx < gr->GetN() ) {
		if ( gr->GetX()[idx] < 10. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
		else idx++;
	}
};

typedef struct
{
	TGraphErrors * grCn;
	TGraphErrors * grVn;
	TGraphErrors * grC2;
	TGraphErrors * grV2;
	TGraphErrors * grC4;
	TGraphErrors * grV4;
	TGraphErrors * grC6;
	TGraphErrors * grV6;
	TGraphErrors * grC8;
	TGraphErrors * grV8;
	TGraphErrors * grV64;
	TGraphErrors * grV86;
	TGraphErrors * grV4V2;
} VnGraph;

void overRideE(TGraphErrors* gr, TGraphErrors* gr1, TGraphErrors* gr2)
{
	for ( int i = 0; i < gr->GetN(); i++ ) {
		double x = gr->GetX()[i];
		double y1 = 0;
		double e1 = 0;
		double y2 = 0;
		double e2 = 0;
		for ( int j = 0; j < gr1->GetN(); j++ ) {
			if ( fabs( gr1->GetX()[j]-x ) < 1. ) {
				y1 = gr1->GetY()[j];
				e1 = gr1->GetEY()[j];
			}
		}

		for ( int j = 0; j < gr2->GetN(); j++ ) {
			if ( fabs( gr2->GetX()[j]-x ) < 1. ) {
				y2 = gr2->GetY()[j];
				e2 = gr2->GetEY()[j];
			}
		}

		gr->GetY()[i] = y1/y2;
		gr->GetEY()[i] = sqrt(e1*e1/y1/y1 + e2*e2/y2/y2) * y2 / y1;
	}
}

void getGraph(TFile * f, VnGraph &gr, int n)
{
	gr.grCn = (TGraphErrors*) f->Get(Form("grC%in", n));
	gr.grVn = (TGraphErrors*) f->Get(Form("grV%in", n));

	gr.grC4 = (TGraphErrors*) f->Get(Form("grC%i4", n));
	gr.grV4 = (TGraphErrors*) f->Get(Form("grV%i4", n));

	gr.grC6 = (TGraphErrors*) f->Get(Form("grC%i6", n));
	gr.grV6 = (TGraphErrors*) f->Get(Form("grV%i6", n));

	gr.grC8 = (TGraphErrors*) f->Get(Form("grC%i8", n));
	gr.grV8 = (TGraphErrors*) f->Get(Form("grV%i8", n));

	gr.grV64 = (TGraphErrors*) f->Get(Form("grV%i64", n));
	gr.grV86 = (TGraphErrors*) f->Get(Form("grV%i86", n));

	if ( gr.grV64 != 0 ) {
		if ( gr.grV64->GetN() != gr.grV6->GetN() ) {
			cout << "#V64 != #V6" << endl;
		}

		overRideE(gr.grV64, gr.grV6, gr.grV4);
	}
	if ( gr.grV86 != 0 ) {
		if ( not gr.grV86 and gr.grV86->GetN() != gr.grV8->GetN() ) {
			cout << "#V86 != #V8" << endl;
		}

		overRideE(gr.grV86, gr.grV8, gr.grV6);
	}

	gr.grV4V2= (TGraphErrors*) f->Get(Form("grV4V2%i", n));
};
