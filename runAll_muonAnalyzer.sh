#////////////////////////////////////////////////////////////////
#////////////////////////////////////////////////////////////////

#/////            Muon Studies for CSA14                     ////

#/////        A. Calderón (IFCA)   18 / 08 / 2014            ////

#////////////////////////////////////////////////////////////////
#////////////////////////////////////////////////////////////////

#root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_GGHWW_S14")';
#root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_Wjets_S14")';

root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_GGHWW_PU20bx25")';
root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_Wjets_PU20bx25")';

#root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_GGHWW_8TeV")';
#root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_Wjets_8TeV")';

root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_DY_PU20bx25")';
#root -l -b -q 'RunPROOF_muonAnalyzer.C("MC_DY_8TeV")';
