{
	double binning[15] = {0, 10, 30, 50, 70, 90, 120, 150, 185, 220, 250, 300, 320, 350, 600}; // from noff.h
	for ( int i = 0 ; i < 14; i++ ) {
		double nevt = 0;
		double sum = 0;
		for ( int j = binning[i]; j < binning[i+1]; j++ ) {
			sum += j * hNoff->GetBinContent(j+1);
			nevt += hNoff->GetBinContent(j+1);
		}
		cout << sum/nevt << ", ";
	}
}
