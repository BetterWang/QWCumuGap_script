#### main plot
root -l -b -q 'plotC.C("grV2_merged.root","grV3_merged.root", "grV2PbPb_sysTight2.root", "grV3PbPb_sysTight2.root", "grV2_pp13.root", "grV3_pp13.root")'


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




## PbPb pixel sysPosEta cumulant v2
root -l 'plot.C("txt/PbPb15_pixel_sysPos/outGraph.root", vector<string>{"grV42", "grV62", "grV82"}, vector<string>{"v_{2}{4}", "v_{2}{6}", "v_{2}{8}"})'
## PbPb pixel sysNegEta cumulant v2
root -l 'plot.C("txt/PbPb15_pixel_sysNeg/outGraph.root", vector<string>{"grV42", "grV62", "grV82"}, vector<string>{"v_{2}{4}", "v_{2}{6}", "v_{2}{8}"})'

################### v24
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV42", vector<string>{"v_{2}{4} |#eta|<2.4", "v_{2}{4} 0<#eta<2.4", "v_{2}{4} -2.4<#eta<0"})'
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV43", vector<string>{"v_{3}{4} |#eta|<2.4", "v_{3}{4} 0<#eta<2.4", "v_{3}{4} -2.4<#eta<0"})'
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV44", vector<string>{"v_{4}{4} |#eta|<2.4", "v_{4}{4} 0<#eta<2.4", "v_{4}{4} -2.4<#eta<0"})'

root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV62", vector<string>{"v_{2}{6} |#eta|<2.4", "v_{2}{6} 0<#eta<2.4", "v_{2}{6} -2.4<#eta<0"})'
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV63", vector<string>{"v_{3}{6} |#eta|<2.4", "v_{3}{6} 0<#eta<2.4", "v_{3}{6} -2.4<#eta<0"})'
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV64", vector<string>{"v_{4}{6} |#eta|<2.4", "v_{4}{6} 0<#eta<2.4", "v_{4}{6} -2.4<#eta<0"})'

root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV82", vector<string>{"v_{2}{8} |#eta|<2.4", "v_{2}{8} 0<#eta<2.4", "v_{2}{8} -2.4<#eta<0"})'
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV83", vector<string>{"v_{3}{8} |#eta|<2.4", "v_{3}{8} 0<#eta<2.4", "v_{3}{8} -2.4<#eta<0"})'
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "txt/PbPb15_pixel_sysPos/outGraph.root", "txt/PbPb15_pixel_sysNeg/outGraph.root", "grV84", vector<string>{"v_{4}{8} |#eta|<2.4", "v_{4}{8} 0<#eta<2.4", "v_{4}{8} -2.4<#eta<0"})'


########## fixed
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent/outGraph.root", "grV42", vector<string>{"v_{2}{4} cumugap", "v_{2}{4} SC", "v_{2}{4} SC"})'
root -l 'plotX.C("txt/PbPb15_pixel/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent/outGraph.root", "grV62", vector<string>{"v_{2}{6} cumugap", "v_{2}{6} SC", "v_{2}{6} SC"})'

root -l 'plotX.C("../SC/txt/PbPb5TeV_Pixel_cent/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent_PosEta/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent_NegEta/outGraph.root", "grV42", vector<string>{"v_{2}{4} SC", "v_{2}{4} 0<#eta<2.4", "v_{2}{4} -2.4<#eta<0"})'



####### SC code Xcheck
#root -l 'plotX.C("../SC/txt/PbPb5TeV_Pixel_cent_PosEta/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent_NegEta/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent/outGraph.root", "grV42", vector<string>{"v_{2}{4} 0<#eta<2.4", "v_{2}{4} -2.4<#eta<0", "v_{2}{4} -2.4<#eta<2.4"})'
root -l 'plotX.C("../SC/txt/PbPb5TeV_Pixel_cent_PosEta/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent_PosEta/outGraph.root", "../SC/txt/PbPb5TeV_Pixel_cent/outGraph.root", "grV42", vector<string>{"v_{2}{4} 0<#eta<2.4", "v_{2}{4} -2.4<#eta<0", "v_{2}{4} -2.4<#eta<2.4"})'

