//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "TreeTestApp.h"
#include "TreeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
TreeTestApp::validParams()
{
  InputParameters params = TreeApp::validParams();
  return params;
}

TreeTestApp::TreeTestApp(InputParameters parameters) : MooseApp(parameters)
{
  TreeTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

TreeTestApp::~TreeTestApp() {}

void
TreeTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  TreeApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"TreeTestApp"});
    Registry::registerActionsTo(af, {"TreeTestApp"});
  }
}

void
TreeTestApp::registerApps()
{
  registerApp(TreeApp);
  registerApp(TreeTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
TreeTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TreeTestApp::registerAll(f, af, s);
}
extern "C" void
TreeTestApp__registerApps()
{
  TreeTestApp::registerApps();
}
