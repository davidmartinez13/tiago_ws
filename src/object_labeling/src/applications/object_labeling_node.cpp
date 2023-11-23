#include <object_labeling/object_labeling.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "plane_segmentation");
  ros::NodeHandle nh;

  //#>>>>TODO: Set the correct topic names and frames
  std::string objects_cloud_topic; // = "?"
  std::string& camera_info_topic; // = "?"
  std::string& camera_frame; // = "?"

  ObjectLabeling labeling(
    objects_cloud_topic,
    camera_info_topic,
    camera_frame);

  // Init
  if(!labeling.initalize(nh))
  {
    return -1;
  }

  // Run
  ros::Rate rate(30);
  while(ros::ok())
  {
    labeling.update(ros::Time::now());
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
