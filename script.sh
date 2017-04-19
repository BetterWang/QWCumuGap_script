
## PbPb pixel cumulant v2
root -l 'plot.C("txt/PbPb15_pixel/outGraph.root", vector<string>{"grV42", "grV62", "grV82"}, vector<string>{"v_{2}{4}", "v_{2}{6}", "v_{2}{8}"})'

## PbPb pixel cumulant v3
root -l 'plot.C("txt/PbPb15_pixel/outGraph.root", vector<string>{"grV43", "grV63", "grV83"}, vector<string>{"v_{3}{4}", "v_{3}{6}", "v_{3}{8}"})'

## PbPb pixel cumulant v4
root -l 'plot.C("txt/PbPb15_pixel/outGraph.root", vector<string>{"grV44", "grV64", "grV84"}, vector<string>{"v_{4}{4}", "v_{4}{6}", "v_{4}{8}"})'
root -l 'plot.C("txt/PbPb15_pixel/outGraph.root", vector<string>{"grV45", "grV65", "grV85"}, vector<string>{"v_{5}{4}", "v_{5}{6}", "v_{5}{8}"})'
root -l 'plot.C("txt/PbPb15_pixel/outGraph.root", vector<string>{"grV46", "grV66", "grV86"}, vector<string>{"v_{6}{4}", "v_{6}{6}", "v_{6}{8}"})'

## HIJING cumulant v2
root -l 'plot.C("txt/HIJING_fEllP_8pct_v2/outGraph.root", vector<string>{"grV42", "grV62", "grV82"}, vector<string>{"v_{2}{4} fEllP_8pct_v2", "v_{2}{6}", "v_{2}{8}"})'
root -l 'plot.C("txt/HIJING_fEllP_8pct_v2/outGraph.root", vector<string>{"grV43", "grV63", "grV83"}, vector<string>{"v_{3}{4} fEllP_8pct_v2", "v_{3}{6}", "v_{3}{8}"}, make_pair<double, double>(1, 99), make_pair<double, double>(-0.05, 0.05))'
root -l 'plot.C("txt/HIJING_fEllP_8pct_v2/outGraph.root", vector<string>{"grV44", "grV64", "grV84"}, vector<string>{"v_{4}{4} fEllP_8pct_v2", "v_{4}{6}", "v_{4}{8}"}, make_pair<double, double>(1, 99), make_pair<double, double>(-0.05, 0.05))'
