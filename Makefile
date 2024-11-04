.PHONY: build
build:
	@ meson compile -C build

.PHONY: crun
crun:
	@ meson compile -C build
	@ echo "Running..."
	@ ./build/manager

.PHONY: run
run:
	@ echo "Running..."
	@ ./build/manager
