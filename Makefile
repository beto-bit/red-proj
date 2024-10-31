.PHONY: crun
crun:
	@ meson compile -C build
	@ ./build/manager

.PHONY: run
run:
	@ ./build/manager
