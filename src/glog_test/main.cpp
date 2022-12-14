#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iomanip>
#include <memory>

#ifdef GLOG_CUSTOM_PREFIX_SUPPORT
void CustomPrefix(std::ostream& os, const google::LogMessageInfo& lmi, void* data)
{
  os << "[" << std::setw(7) << std::setfill(' ') << lmi.severity << " "
    << std::setw(4) << 1900 + lmi.time.year()
    << std::setw(2) << std::setfill('0') << 1 + lmi.time.month()
    << std::setw(2) << lmi.time.day()
    << ' '
    << std::setw(2) << lmi.time.hour() << ':'
    << std::setw(2) << lmi.time.min() << ':'
    << std::setw(2) << lmi.time.sec() << ' '
    << lmi.filename << ":" << lmi.line_number << "]";
}
#endif

int main(int argc, char* argv[])
{
  gflags::ParseCommandLineFlags(&argc, &argv, true);
#ifdef GLOG_CUSTOM_PREFIX_SUPPORT
  google::InitGoogleLogging(argv[0], &CustomPrefix);
#else
  google::InitGoogleLogging(argv[0]);
#endif

  std::shared_ptr<void> callback(nullptr, [](void*){
    google::ShutdownGoogleLogging();
  });

  LOG(INFO) << "Hello, INFO!";
  LOG(WARNING) << "Hello, WARNING!";
  LOG(ERROR) << "Hello, ERROR!";

  return 0;
}
