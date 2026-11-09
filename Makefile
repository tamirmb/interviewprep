# Interview prep build: each problems/<name>.cpp is its own Catch2 test binary.
#
#   make <name>              build and run one problem, e.g. `make two_sum`
#   make <name> ARGS='[tag]' pass Catch2 arguments (tags, -s, --durations yes, ...)
#   make test                build and run every problem
#   make new name=<name>     create problems/<name>.cpp from the template
#   make list                list problems
#   make clean               remove build output
#   make help                show this help

CXX       ?= c++
CXXFLAGS  := -std=c++20 -g -O1 -Ithird_party/catch2 -Icommon -MMD -MP
WARNINGS  := -Wall -Wextra -Wpedantic

BUILD     := build
CATCH_OBJ := $(BUILD)/catch_amalgamated.o
PROBLEMS  := $(basename $(notdir $(wildcard problems/*.cpp)))
BINS      := $(addprefix $(BUILD)/,$(PROBLEMS))

.PHONY: test list new clean help $(PROBLEMS)

test: $(BINS)
	@status=0; for bin in $(BINS); do echo "== $$(basename $$bin)"; $$bin $(ARGS) || status=1; done; exit $$status

$(PROBLEMS): %: $(BUILD)/%
	@./$< $(ARGS)

$(BUILD)/%: problems/%.cpp $(CATCH_OBJ)
	$(CXX) $(CXXFLAGS) $(WARNINGS) $< $(CATCH_OBJ) $(LDFLAGS) -o $@

# Catch2 is slow to compile, so build it once and reuse the object
$(CATCH_OBJ): third_party/catch2/catch_amalgamated.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

list:
	@printf '%s\n' $(PROBLEMS)

new:
	@test -n "$(name)" || { echo "usage: make new name=<problem>"; exit 1; }
	@test ! -e problems/$(name).cpp || { echo "problems/$(name).cpp already exists"; exit 1; }
	@sed 's/PROBLEM_NAME/$(name)/g' templates/problem.cpp > problems/$(name).cpp
	@echo "created problems/$(name).cpp"

clean:
	rm -rf $(BUILD)

# Print the usage block from the header comment so it stays the single source of truth
help:
	@sed -n 's/^#   make/make/p' $(firstword $(MAKEFILE_LIST))

-include $(wildcard $(BUILD)/*.d)
