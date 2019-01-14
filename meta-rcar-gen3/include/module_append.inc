# Fix error: openssl/bio.h: No such file or directory
do_make_scripts() {
unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	make CC="${KERNEL_CC}" LD="${KERNEL_LD}" AR="${KERNEL_AR}" \
	           HOSTCC="${BUILD_CC} ${BUILD_CFLAGS} ${BUILD_LDFLAGS}" HOSTCPP="${BUILD_CPP}" \
           -C ${STAGING_KERNEL_DIR} O=${STAGING_KERNEL_BUILDDIR} scripts prepare
}
do_make_scripts[depends] += "openssl-native:do_populate_sysroot"