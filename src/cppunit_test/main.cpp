#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main(int argc,char* argv[])
{
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry =
      CppUnit::TestFactoryRegistry::getRegistry("alltest");
  runner.addTest(registry.makeTest());
  return runner.run();
}
