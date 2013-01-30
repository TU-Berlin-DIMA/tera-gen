#include "core/constants.h"
#include "core/Frontend.h"

namespace Myriad {

/**
 * Application name.
 */
const String Constant::APP_NAME = "tera-gen - Parallel Data Generator for the TeraSort Benchmark";

/**
 * Application version.
 */
const String Constant::APP_VERSION = "1.0.0";

} // Myriad namespace

// define the application main method
POCO_APP_MAIN(Myriad::Frontend)
