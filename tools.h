
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
		if ( gr->GetX()[idx] < 30. or gr->GetX()[idx] > 350 ) gr->RemovePoint( idx );
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

