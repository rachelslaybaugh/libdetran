#------------------------------------------------------------------------------#
# libdetran/src/geometry/test/CMakeLists.txt
#------------------------------------------------------------------------------#

#------------------------------------------------------------------------------#
# Create test executables
#------------------------------------------------------------------------------#

ADD_EXECUTABLE(test_Mesh1D                  test_Mesh1D.cc)
TARGET_LINK_LIBRARIES(test_Mesh1D           geometry utilities angle)

ADD_EXECUTABLE(test_Mesh2D                  test_Mesh2D.cc)
TARGET_LINK_LIBRARIES(test_Mesh2D           geometry utilities angle)

ADD_EXECUTABLE(test_Mesh3D                  test_Mesh3D.cc)
TARGET_LINK_LIBRARIES(test_Mesh3D           geometry utilities angle)

ADD_EXECUTABLE(test_PinCell                 test_PinCell.cc)
TARGET_LINK_LIBRARIES(test_PinCell          geometry utilities angle)

ADD_EXECUTABLE(test_Segment                 test_Segment.cc)
TARGET_LINK_LIBRARIES(test_Segment          geometry utilities angle)

ADD_EXECUTABLE(test_Track                   test_Track.cc)
TARGET_LINK_LIBRARIES(test_Track            geometry utilities angle)

ADD_EXECUTABLE(test_Tracker                 test_Tracker.cc)
TARGET_LINK_LIBRARIES(test_Tracker          geometry utilities angle)

#------------------------------------------------------------------------------#
# Define tests
#------------------------------------------------------------------------------#

ADD_TEST(test_Mesh1D 	      test_Mesh1D 	  0)
ADD_TEST(test_Mesh2D 	      test_Mesh2D 	  0)
ADD_TEST(test_Mesh3D 	      test_Mesh3D     0)
ADD_TEST(test_PinCell         test_PinCell    0)
ADD_TEST(test_Segment         test_Segment    0)
ADD_TEST(test_Track           test_Track      0)
ADD_TEST(test_Tracker_2x2     test_Tracker    0)
ADD_TEST(test_Tracker_3x3     test_Tracker    1)
