set(KIT PolySeg)

create_test_sourcelist(Tests ${KIT}CxxTests.cxx
  vtkSegmentationTest1.cxx
  vtkSegmentationConverterTest1.cxx
  )

add_executable(${KIT}CxxTests ${Tests})
target_link_libraries(${KIT}CxxTests ${PROJECT_NAME})
set_target_properties(${KIT}CxxTests PROPERTIES FOLDER ${${PROJECT_NAME}_FOLDER})

simple_test( vtkSegmentationTest1 )
simple_test( vtkSegmentationConverterTest1 )
