file(GLOB_RECURSE rex_impl CONFIGURE_DEPENDS "*.cxx")
target_sources(rex PUBLIC ${rex_impl})