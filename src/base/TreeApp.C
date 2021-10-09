#include "TreeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
TreeApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

TreeApp::TreeApp(InputParameters parameters) : MooseApp(parameters)
{
  TreeApp::registerAll(_factory, _action_factory, _syntax);
}

TreeApp::~TreeApp() {}

void
TreeApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"TreeApp"});
  Registry::registerActionsTo(af, {"TreeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
TreeApp::registerApps()
{
  registerApp(TreeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TreeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TreeApp::registerAll(f, af, s);
}
extern "C" void
TreeApp__registerApps()
{
  TreeApp::registerApps();
}
