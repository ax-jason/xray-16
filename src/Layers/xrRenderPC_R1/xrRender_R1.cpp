#include "stdafx.h"
#include "Layers/xrRender/dxRenderFactory.h"
#include "Layers/xrRender/dxUIRender.h"
#include "Layers/xrRender/dxDebugRender.h"

#pragma comment(lib, "xrEngine.lib")

void SetupEnvR1()
{
    GEnv.Render = &RImplementation;
    GEnv.RenderFactory = &RenderFactoryImpl;
    GEnv.DU = &DUImpl;
    GEnv.UIRender = &UIRenderImpl;
#ifdef DEBUG
    GEnv.DRender = &DebugRenderImpl;
#endif
    xrRender_initconsole();
}

// This must not be optimized by compiler
#pragma optimize("", off)
static const volatile class GEnvHelper
{
public:
    GEnvHelper()
    {
        GEnv.SetupR1 = SetupEnvR1;
    }
} helper;
#pragma optimize("", on)

