#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := morse

EXTRA_COMPONENT_DIRS = $(IDF_PATH)/examples/common_components/led_strip

include $(IDF_PATH)/make/project.mk