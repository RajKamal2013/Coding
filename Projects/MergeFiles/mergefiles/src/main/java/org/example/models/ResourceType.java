package org.example.models;

public enum ResourceType {
    VSPHERE("Vsphere"),
    NSX_T("NsxtCluster"),
    NSX_T_TRANSPORT_NODE("transportNode"),
    CLUSTER("cluster"),
    HOST("host"),
    SDDC_MANAGER("sddcManager"),
    VC_MANAGER("VcManager"),
    DVS("dvs"),
    DOMAIN("domain"),

    ;

    ResourceType(String resourceName) {
    }
}
