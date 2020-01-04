extern "C" {
    int ifc_set_throttle(const char * /*ifname*/, int /*rxKbps*/, int /*txKbps*/) { return 0; }
}

extern "C" {
    int ifc_set_txq_state(const char * /*ifname*/, int /*rxKbps*/, int /*txKbps*/) { return 0; }
}
