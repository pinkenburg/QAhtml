#ifndef CALO_CALOGOODRUNCHECKER_H
#define CALO_CALOGOODRUNCHECKER_H

#include <string>
#include <TLatex.h>

class TCanvas;
class TPad;
class TH1;
class TH2;
class CaloGoodRunChecker

{
 public:
  CaloGoodRunChecker() {}
  ~CaloGoodRunChecker() {}

  void SetHistfile(std::string hfile) {histfile = hfile;}
  std::string MakeHotColdDeadMaps();
  void DeleteHotColdDeadMaps();
  void CemcCheckGoodRun();
  std::string CemcGetComments();
  TCanvas* CemcMakeSummary();
  void CemcWriteDB();
  void ihcalCheckGoodRun();
  TCanvas* ihcalMakeSummary();
  void ohcalCheckGoodRun();
  TCanvas* ohcalMakeSummary();
  void myText(double x, double y, int color, const char *text, double tsize = 0.04);

  std::string histfile = "";
  std::string histprefix = "h_CaloValid_";
  std::string mapsfile_prefix = "HotColdDeadMaps_";
  std::string mapsfile = "";
  TH2* cemc_hcdmap = nullptr;
  TH2* ihcal_hcdmap = nullptr;
  TH2* ohcal_hcdmap = nullptr;

  int n_events= 0;
  bool cemc_isgood = false;
  bool cemc_fails_events = false;
  bool cemc_fails_badtowers = false;
  bool cemc_fails_timing = false;
  bool cemc_fails_vertex = false;
  int cemc_hot_towers = 999999;
  int cemc_cold_towers = 999999;
  int cemc_dead_towers = 999999;
  float cemc_time_mean = 999.9;
  float cemc_time_sigma = 999.9;
  bool ihcal_isgood = false;
  bool ihcal_fails_events = false;
  bool ihcal_fails_badtowers = false;
  bool ihcal_fails_timing = false;
  bool ihcal_fails_vertex = false;
  int ihcal_hot_towers = 999999;
  int ihcal_cold_towers = 999999;
  int ihcal_dead_towers = 999999;
  float ihcal_time_mean = 999.9;
  float ihcal_time_sigma = 999.9;
  bool ohcal_isgood = false;
  bool ohcal_fails_events = false;
  bool ohcal_fails_badtowers = false;
  bool ohcal_fails_timing = false;
  bool ohcal_fails_vertex = false;
  int ohcal_hot_towers = 999999;
  int ohcal_cold_towers = 999999;
  int ohcal_dead_towers = 999999;
  float ohcal_time_mean = 999.9;
  float ohcal_time_sigma = 999.9;
  float vtxz_mean = 999.9;
  float vtxz_sigma = 999.9;
};

#endif
