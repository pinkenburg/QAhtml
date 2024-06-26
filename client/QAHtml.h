#ifndef QA_CLIENT_QAHTML_H
#define QA_CLIENT_QAHTML_H

#include <filesystem>
#include <set>
#include <string>

/**@name Helper class to centralize HTML generation code.
 */

class QAHtml
{
 public:
  QAHtml(const char* topdir);
  virtual ~QAHtml() {}

  /** Generate a bit of the navigation menu for a given file (link).
   *  @param path the path as it will appear in the menu
   *  @param relfilename the filename that will be served when using
   *  path in the menu (must not be a fullpathname, but a plain filename).
   */
  void addMenu(const std::string& header, const std::string& path,
               const std::string& relfilename);

  /** Generate filenames, to be used to produce e.g. gif or html files.
   *  @param drawer the QADraw child class for which filename must be built
   *  @param basefilename the beginning of the filename
   *  (will be completed e.g. with the run number by this method)
   *  @param ext the extension of the file (e.g. gif or html)
   *  @return fullfilename = path+filename of the generated filename.
   *  @return filename = only filename of the generated filename
   */
  void namer(const std::string& header, const std::string& basefilename,
             const std::string& ext,
             std::string& fullfilename,
             std::string& filename);

  /** Generate a full filename from specified pieces, *and* register
   * the file to the navigation menu
   * @param drawer the QADraw child class for which filename must be built
   * @param path the path that will be used in the *navigation menu*
   * @param basefilename the beginning of the filename
   * (will be completed e.g. with the run number by this method)
   * @param ext the extension of the file (e.g. gif or html)
   * @return the full filename (i.e. full path + filename)
   */
  std::string registerPage(const std::string& header,
                           const std::string& path,
                           const std::string& basefilename,
                           const std::string& ext);

  void runNumber(const int runnumber) { fRunNumber = runnumber; }
  int runNumber() const { return fRunNumber; }

  void RunType(const std::string& rtyp);
  std::string RunType() const { return runtype; }

  void verbosity(const int v) { fVerbosity = v; }
  int Verbosity() const { return fVerbosity; }

 private:
  void plainHtmlMenu(const std::set<std::string>&);
  void runInit();
  std::string runRange();
  void set_group_sticky_bit(const std::filesystem::path& dir);
  int fVerbosity{0};
  int fRunNumber{0};
  std::string fHtmlDir;
  std::string fHtmlRunDir;
  std::string runtype{"unknown"};
};

#endif  // QA_CLIENT_QAHTML_H
