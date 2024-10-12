# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CoffeeMachine_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CoffeeMachine_autogen.dir\\ParseCache.txt"
  "CoffeeMachine_autogen"
  )
endif()
