# CMake generated Testfile for 
# Source directory: /home/hawrk/github/hawrk/ros2/param_ws
# Build directory: /home/hawrk/github/hawrk/ros2/param_ws/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cppcheck "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/cppcheck.xunit.xml" "--package-name" "param_ws" "--output-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/ament_cppcheck/cppcheck.txt" "--command" "/opt/ros/galactic/bin/ament_cppcheck" "--xunit-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/cppcheck.xunit.xml" "--include_dirs" "/home/hawrk/github/hawrk/ros2/param_ws/include")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/hawrk/github/hawrk/ros2/param_ws" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/opt/ros/galactic/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;61;ament_add_test;/opt/ros/galactic/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;83;ament_cppcheck;/opt/ros/galactic/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;37;ament_package;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/lint_cmake.xunit.xml" "--package-name" "param_ws" "--output-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/galactic/bin/ament_lint_cmake" "--xunit-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/hawrk/github/hawrk/ros2/param_ws" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/opt/ros/galactic/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/opt/ros/galactic/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/galactic/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;37;ament_package;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;0;")
add_test(uncrustify "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/uncrustify.xunit.xml" "--package-name" "param_ws" "--output-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/ament_uncrustify/uncrustify.txt" "--command" "/opt/ros/galactic/bin/ament_uncrustify" "--xunit-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/hawrk/github/hawrk/ros2/param_ws" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/opt/ros/galactic/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;65;ament_add_test;/opt/ros/galactic/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;34;ament_uncrustify;/opt/ros/galactic/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;37;ament_package;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/xmllint.xunit.xml" "--package-name" "param_ws" "--output-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/ament_xmllint/xmllint.txt" "--command" "/opt/ros/galactic/bin/ament_xmllint" "--xunit-file" "/home/hawrk/github/hawrk/ros2/param_ws/build/test_results/param_ws/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/hawrk/github/hawrk/ros2/param_ws" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/opt/ros/galactic/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/galactic/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/galactic/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/galactic/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/galactic/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;37;ament_package;/home/hawrk/github/hawrk/ros2/param_ws/CMakeLists.txt;0;")