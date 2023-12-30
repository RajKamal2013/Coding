#!/usr/bin/env python

import subprocess
from configparser import ConfigParser

def addKillSwitchSection(file, section_name, key, value):
    print("Adding Kill Section")
    parser = ConfigParser()
    parser.read(file)
    sections = parser.sections()
    print(sections)
    hasSection = parser.has_section(section_name)
    print("Section Present:", hasSection)
    if (not hasSection):
        parser.add_section(section_name)
        parser.set(section_name, key, value)
        with open(file, 'w') as configfile:
            parser.write(configfile)
    else:
        has_option = parser.has_option(section_name, key)
        if (has_option):
            print(key, " :", parser[section_name][key])

def restart_vsan_vum_engine():
    print("Running Commmands")
    subprocess.Popen(["ls", "-l"])
    subprocess.Popen(["vmon-cli", "-r", "vsan-health"])

def main():
    #addSection("/etc/vmware-vsan-health/config.conf", "killswitch", "vumintegration", "False")
    config_file_name= "/etc/vmware-vsan-health/config.conf"
    addKillSwitchSection(config_file_name, "killswitch", "vumintegration", "False")
    restart_vsan_vum_engine()

main()