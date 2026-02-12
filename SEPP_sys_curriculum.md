# Purpose and Scope

Defines execution strategy, learning path, and project management standards for systematic progression through 60 systems engineering projects. Governs project selection, skill prerequisite validation, complexity management, and milestone tracking across 4-year learning curriculum.

# Execution Context

- Agent operates as systems engineering learning coach and project architect
- Applies to: foundational tools through advanced distributed systems (60 projects total)
- Output: project plans, implementation guidance, prerequisite validation, progress tracking
- Timeline: 3.5-4 years sequential learning with dependency-aware progression
- Integration: References web-app-builder.md, build-validator.md, code-architect.md, code-simplifier.md, verify-app.md, oncall-guide.md

# Authoritative Sources of Truth

1. Systems engineering project progression document (tier structure and dependencies)
2. code-architect.md (system design for each project)
3. code-simplifier.md (complexity constraints for educational implementations)
4. verify-app.md (project completion and quality criteria)
5. build-validator.md (environment setup and build verification)
6. web-app-builder.md (web-based demonstration and visualization projects)
7. User's current skill level and completed projects

# Project Tier Structure

## Tier 1: Foundational Tools (Weeks 1-8)
**Core concepts:** Data structures, I/O, parsing, basic algorithms

**Projects:**
1. Text editor
2. Shell
3. Memory allocator
4. Scripting language
5. Package manager
6. Version control system
7. Static code analyzer
8. Profiler

**Prerequisites:** Basic programming knowledge, data structures understanding

**Complexity targets (code-simplifier.md):**
- Functions < 50 lines
- Cyclomatic complexity < 10
- No premature abstractions
- Educational simplicity over production completeness

## Tier 2: Low-Level Systems (Months 3-6)
**Core concepts:** Memory management, process concepts

**Projects:**
9. Disassembler
10. Debugger
11. CPU emulator
12. Scheduler
13. File system
14. Encryption algorithm
15. Key-value store

**Prerequisites:** Tier 1 completion (memory allocator, parsing fundamentals)

**Dependencies:**
- Memory allocator → Scheduler → File system
- CPU emulator → Debugger
- File system → Key-value store

## Tier 3: Compilation & Language Systems (Months 7-10)
**Core concepts:** Parsing, binary formats, CPU understanding

**Projects:**
16. Compiler
17. Programming language
18. Compiler backend (LLVM target)
19. Compiler optimizer
20. Runtime (like Node.js)
21. Scripting sandbox

**Prerequisites:** Tier 1 (scripting language), Tier 2 (CPU emulator, disassembler)

**Dependencies:**
- Scripting language → Compiler → Programming language → Compiler backend → Runtime

## Tier 4: Networking & Distributed Systems (Months 11-14)
**Core concepts:** I/O, protocols, concurrency

**Projects:**
22. Network protocol
23. Networking stack (TCP/IP)
24. Web server
25. Reverse proxy
26. Load balancer
27. API gateway
28. Cache system (like Redis)
29. Message broker (like Kafka)
30. Authentication server (OAuth2/OIDC)

**Prerequisites:** Tier 1 (I/O fundamentals), Tier 2 (file system)

**Dependencies:**
- Network protocol → TCP/IP stack → Web server → Reverse proxy → API gateway
- Key-value store (Tier 2) → Cache system

## Tier 5: Data Systems (Months 15-17)
**Core concepts:** Storage, indexing, query processing

**Projects:**
31. Database
32. Query language
33. Database driver
34. Search engine

**Prerequisites:** Tier 2 (key-value store, file system), Tier 3 (parser)

**Dependencies:**
- Key-value store → Database → Query language → Search engine

## Tier 6: Containerization & Virtualization (Months 18-21)
**Core concepts:** OS concepts, process isolation, filesystems

**Projects:**
35. Container runtime
36. Virtual machine
37. Hypervisor
38. Container orchestrator (like Kubernetes)
39. Distributed file system

**Prerequisites:** Tier 2 (file system, scheduler, CPU emulator)

**Dependencies:**
- File system → Container runtime → Container orchestrator
- CPU emulator → Virtual machine → Hypervisor

## Tier 7: Operating Systems (Months 22-26)
**Core concepts:** ALL previous low-level knowledge

**Projects:**
40. Operating system bootloader
41. Operating system kernel (assembly)
42. Microkernel
43. Operating system scheduler
44. Operating system
45. Operating system for embedded devices

**Prerequisites:** ALL Tiers 1-2, portions of Tier 6

**Critical dependency path:**
- Memory allocator → Scheduler → File system → OS kernel → Full OS

## Tier 8: Graphics & Multimedia (Months 27-30)
**Core concepts:** Graphics algorithms, real-time processing

**Projects:**
46. Graphics renderer (rasterizer)
47. Graphics renderer (ray tracer)
48. Audio engine
49. Physics engine
50. Game engine

**Prerequisites:** Tier 1 (basic algorithms), linear algebra, vector math

**Independent path:** Can parallel with other tiers

## Tier 9: UI & Browser Systems (Months 31-35)
**Core concepts:** Graphics, parsing, networking

**Projects:**
51. Window manager
52. GUI toolkit
53. IDE
54. Browser engine (parser/renderer)
55. Browser

**Prerequisites:** Tier 3 (parser), Tier 4 (networking), Tier 8 (graphics)

**Dependencies:**
- Graphics renderer → GUI toolkit → Browser engine → Browser

## Tier 10: Advanced Distributed Systems (Months 36-40)
**Core concepts:** Cryptography, networking, consensus

**Projects:**
56. Blockchain
57. Blockchain consensus algorithm
58. Zero-knowledge proof system
59. CI/CD system

**Prerequisites:** Tier 2 (encryption), Tier 4 (networking), Tier 5 (data systems)

## Tier 11: Machine Learning (Months 41-44)
**Core concepts:** Linear algebra, calculus, tensor operations

**Projects:**
60. Machine learning framework

**Prerequisites:** Advanced mathematics, GPU programming knowledge

**Independent specialization:** Requires separate mathematical foundation

# Planning and Execution Rules

## Project Selection Protocol

**Before starting any project:**
1. Verify tier prerequisites completed
2. Validate dependency chain satisfied
3. Consult code-architect.md for system design approach
4. Set complexity targets per code-simplifier.md
5. Define verification criteria per verify-app.md
6. Document architectural decisions (ADR format from code-architect.md)

**Prerequisite validation:**
```
Current project: [Name]
Tier: [Number]
Required prerequisites:
- [ ] Tier [X] complete
- [ ] Project [Y] complete (direct dependency)
- [ ] Concept [Z] understood

Status: [READY | BLOCKED]
Blockers: [List missing prerequisites]
```

## Project Scope Definition

**Educational vs production (code-simplifier.md):**
- Build simplified versions extracting educational value
- Not production-grade implementations
- Focus on core concepts over edge cases
- Complexity appropriate to learning stage

**Scope documentation (code-architect.md):**
```
# Project: [Name]
## Educational Goals
- Understand [core concept 1]
- Implement [fundamental mechanism]
- Learn [system interaction pattern]

## Scope Boundaries
In scope:
- [Core functionality]
- [Essential features]

Out of scope:
- [Production optimizations]
- [Advanced edge cases]
- [Non-essential features]

## Success Criteria (verify-app.md)
- [ ] Core mechanism functional
- [ ] Educational objectives met
- [ ] Code demonstrably understandable
```

## Architecture Planning Per Project

**Apply code-architect.md for each project:**
1. Define system boundaries
2. Identify core components
3. Establish data flow
4. Document integration points
5. Specify simplified technology stack
6. Define educational deployment model

**Complexity constraints (code-simplifier.md):**
- Cyclomatic complexity < 10 per function
- Component files < 500 lines
- Clear separation of concerns
- Minimal abstractions (educational clarity)
- No premature optimization

## Implementation Workflow

**Development sequence:**
1. **Architecture phase** (code-architect.md)
   - Write ADR for major decisions
   - Sketch component diagram
   - Define interfaces
   - Plan data structures

2. **Implementation phase** (code-simplifier.md + web-app-builder.md if web-based)
   - Build minimal working version first
   - Apply simplification patterns
   - Measure complexity continuously
   - Document non-obvious code

3. **Verification phase** (verify-app.md + build-validator.md)
   - Run functional tests
   - Verify educational objectives met
   - Check complexity metrics
   - Validate build process

4. **Documentation phase**
   - Write project summary
   - Document key learnings
   - Note prerequisite concepts used
   - Identify follow-on projects enabled

# Project-Specific Guidelines

## Tier 1 Projects (Foundational)

### Text Editor (Project 1)
**Architecture (code-architect.md):**
- Components: Buffer manager, cursor controller, file I/O, UI renderer
- Data structures: Gap buffer or rope for text storage
- Operations: Insert, delete, save, load

**Complexity targets (code-simplifier.md):**
- Buffer operations < 30 lines each
- No complex abstractions
- Direct data structure manipulation

**Verification (verify-app.md):**
- [ ] Can create/open/save files
- [ ] Insert/delete operations work
- [ ] Cursor movement functional
- [ ] No data corruption

### Shell (Project 2)
**Dependencies:** File I/O concepts from text editor

**Architecture:**
- Components: Parser, executor, built-in commands, process manager
- Process concepts: fork/exec pattern
- Environment: Variable management

**Complexity targets:**
- Parser < 100 lines
- Each built-in command < 30 lines
- No complex job control initially

### Memory Allocator (Project 3)
**Critical foundation for:** Scheduler, file system, all future projects

**Architecture:**
- Algorithms: First-fit or best-fit
- Data structures: Free list
- Operations: malloc, free, coalesce

**Complexity targets:**
- Core allocator < 200 lines total
- Clear boundary detection
- No advanced algorithms (slab, buddy)

**Verification:**
- [ ] No memory leaks (valgrind)
- [ ] Handles fragmentation
- [ ] Coalescing works
- [ ] Alignment correct

### Scripting Language (Project 4)
**Foundation for:** Compiler (Project 16)

**Architecture:**
- Components: Lexer, parser, AST, interpreter
- Features: Variables, functions, control flow
- Type system: Dynamic typing

**Complexity targets:**
- Lexer < 150 lines
- Parser < 200 lines
- Interpreter < 250 lines
- Total < 600 lines

**Verification:**
- [ ] Variables work
- [ ] Functions callable
- [ ] Control flow correct
- [ ] Recursion supported

## Tier 2 Projects (Low-Level Systems)

### CPU Emulator (Project 11)
**Foundation for:** Debugger, virtual machine, hypervisor

**Architecture:**
- Components: Register file, ALU, memory, instruction decoder
- ISA: Simplified (8-bit or subset of RISC-V)
- Operations: Fetch-decode-execute cycle

**Complexity targets:**
- Instruction set < 20 instructions
- Decoder < 100 lines (switch statement acceptable)
- No pipelining or caching

**Verification:**
- [ ] All instructions execute correctly
- [ ] Flags set properly
- [ ] Memory access works
- [ ] Can run simple programs

### File System (Project 13)
**Critical foundation for:** Container runtime, OS kernel, distributed file system

**Architecture:**
- Components: Inode table, block allocator, directory structure
- Operations: Create, read, write, delete, mkdir
- Metadata: Basic permissions, timestamps

**Complexity targets:**
- Inode structure < 50 lines
- Block allocator < 100 lines
- No journaling initially
- No caching initially

**Verification (verify-app.md):**
- [ ] Files persist across restarts
- [ ] Directories navigable
- [ ] No data corruption
- [ ] Space reclaimed on delete

## Tier 3 Projects (Compilation)

### Compiler (Project 16)
**Dependencies:** Scripting language (Project 4), CPU emulator (Project 11)

**Architecture:**
- Pipeline: Lexer → Parser → Semantic analysis → Code generation
- Target: CPU emulator from Project 11
- Source language: Subset of C or custom language

**Complexity targets:**
- Lexer < 200 lines
- Parser < 300 lines
- Codegen < 400 lines
- Total < 1000 lines

**Verification:**
- [ ] Compiles valid programs
- [ ] Generated code runs on emulator
- [ ] Error messages helpful
- [ ] Basic optimizations work

## Tier 4 Projects (Networking)

### Web Server (Project 24)
**Dependencies:** Network protocol (22), TCP/IP stack (23)

**Can use web-app-builder.md for web-based demo/testing interface**

**Architecture:**
- Components: Socket listener, HTTP parser, router, response builder
- Concurrency: Threading or async I/O
- Features: Static files, routing, headers

**Complexity targets:**
- HTTP parser < 200 lines
- Router < 100 lines
- Single-threaded initially acceptable

**Verification:**
- [ ] Serves static files
- [ ] Handles concurrent requests
- [ ] Correct HTTP responses
- [ ] No memory leaks under load

**web-app-builder.md integration:**
- Build web-based test client
- Visualize request/response flow
- Interactive demo of HTTP parsing

## Tier 7 Projects (Operating Systems)

### Operating System Kernel (Project 41)
**Dependencies:** ALL Tier 1-2, memory allocator, scheduler, file system

**Architecture:**
- Components: Boot code, interrupt handlers, syscall interface, drivers
- Initialization: Hardware setup, memory management, process 0
- Syscalls: Minimal set (fork, exec, exit, read, write)

**Complexity targets:**
- Kernel core < 2000 lines assembly + C
- 10-15 syscalls maximum
- Single CPU, no SMP

**Verification:**
- [ ] Boots successfully
- [ ] Syscalls functional
- [ ] Can run userspace programs
- [ ] No crashes under normal use
- [ ] Memory protection works

**Reality check:** This is a multi-month project, simplified significantly from production OS

## Tier 9 Projects (Browser Systems)

### Browser (Project 55)
**Dependencies:** Graphics renderer (46), GUI toolkit (52), Browser engine (54), networking (Tier 4)

**Can implement UI using web-app-builder.md web technologies**

**Architecture:**
- Components: HTML/CSS parser, DOM, layout engine, renderer, JS runtime, networking
- Integration: All previous components
- Features: Basic HTML, CSS subset, minimal JavaScript

**Complexity targets:**
- Each major component < 1000 lines
- Total < 5000 lines (highly simplified)
- Subset of HTML5/CSS3

**web-app-builder.md integration:**
- Use React for browser UI chrome
- Demonstrate rendering pipeline
- Visualize DOM tree construction

**Verification:**
- [ ] Renders basic HTML/CSS
- [ ] Handles user input
- [ ] Executes simple JS
- [ ] Navigates between pages
- [ ] No crashes on malformed HTML

# Web-Based Demonstration Projects (web-app-builder.md)

## Projects Suitable for Web Artifacts

**Tier 1:**
- Text editor (React-based editor)
- Static code analyzer (visualize AST)

**Tier 2:**
- CPU emulator (visualize registers, memory)
- Disassembler (interactive binary viewer)

**Tier 3:**
- Compiler (visualize compilation stages)
- Scripting language (online interpreter)

**Tier 4:**
- Network protocol visualizer
- Web server demo/tester

**Tier 5:**
- Query language playground
- Database visualizer

**Web artifact guidelines (web-app-builder.md):**
- Use React for complex state management
- Visualize internal state
- Interactive debugging
- Educational demonstrations
- Real-time feedback

**Example: CPU Emulator Web Demo**
```javascript
// Architecture per code-architect.md
// Simplified per code-simplifier.md
// Web implementation per web-app-builder.md

export default function CPUEmulator() {
  const [registers, setRegisters] = useState({});
  const [memory, setMemory] = useState([]);
  const [pc, setPc] = useState(0);
  
  // Fetch-decode-execute cycle
  const step = () => {
    const instruction = memory[pc];
    const decoded = decode(instruction);
    execute(decoded);
    setPc(pc + 1);
  };
  
  return (
    <div className="grid grid-cols-2 gap-4">
      <RegisterView registers={registers} />
      <MemoryView memory={memory} pc={pc} />
      <Controls onStep={step} onReset={reset} />
    </div>
  );
}
```

# Dependency Validation and Progression

## Critical Dependency Paths

### Path 1: OS Development
```
Memory allocator (3)
  → Scheduler (12)
    → File system (13)
      → OS kernel (41)
        → Full OS (44)
```

**Validation at each stage:**
- Memory allocator: Can allocate/free without leaks
- Scheduler: Can time-slice processes
- File system: Can persist data reliably
- OS kernel: Can execute all previous components

### Path 2: Compiler Development
```
Scripting language (4)
  → Compiler (16)
    → Programming language (17)
      → Compiler backend (18)
        → Runtime (20)
```

**Validation at each stage:**
- Scripting language: Can parse and execute programs
- Compiler: Can generate executable code
- Programming language: Type system functional
- Runtime: Can execute compiled programs with standard library

### Path 3: Network Stack
```
Network protocol (22)
  → TCP/IP stack (23)
    → Web server (24)
      → Reverse proxy (25)
        → API gateway (27)
```

**Validation at each stage:**
- Network protocol: Reliable message delivery
- TCP/IP: Full network communication
- Web server: HTTP request handling
- Each layer builds on previous

### Path 4: Container Stack
```
File system (13)
  → Container runtime (35)
    → Container orchestrator (38)
```

**Validation at each stage:**
- File system: Image layer storage
- Container runtime: Process isolation
- Orchestrator: Multi-container management

### Path 5: VM/Hypervisor Stack
```
CPU emulator (11)
  → Virtual machine (36)
    → Hypervisor (37)
```

**Validation at each stage:**
- CPU emulator: Instruction execution
- Virtual machine: Full system emulation
- Hypervisor: Multi-VM management

### Path 6: Browser Stack
```
Graphics renderer (46)
  → GUI toolkit (52)
    → Browser engine (54)
      → Browser (55)
```

**Validation at each stage:**
- Graphics: Can render primitives
- GUI toolkit: Widget system functional
- Browser engine: HTML/CSS parsing and layout
- Browser: Full integration

### Path 7: Database Stack
```
Key-value store (15)
  → Database (31)
    → Query language (32)
      → Search engine (34)
```

**Validation at each stage:**
- Key-value store: Basic persistence
- Database: ACID transactions
- Query language: SQL-like operations
- Search engine: Indexing and ranking

## Prerequisite Validation Checklist

**Before starting project [N]:**
```
Project: [Name]
Tier: [Number]

Direct dependencies:
- [ ] Project [X]: [Concept needed] - Status: [Complete/Incomplete]
- [ ] Project [Y]: [Concept needed] - Status: [Complete/Incomplete]

Conceptual prerequisites:
- [ ] Understand [concept 1] from [source]
- [ ] Can implement [pattern] from [project]
- [ ] Familiar with [technology/technique]

Environment prerequisites (build-validator.md):
- [ ] Development environment set up
- [ ] Required tools installed
- [ ] Dependencies available

Decision: [PROCEED | DEFER | LEARN_PREREQUISITE]
```

# Verification and Milestone Tracking

## Project Completion Criteria (verify-app.md)

**Every project must satisfy:**

**Functional completeness:**
- [ ] Core educational objectives achieved
- [ ] All critical features implemented
- [ ] System demonstrates key concepts
- [ ] Integration with dependent projects works

**Code quality (code-simplifier.md):**
- [ ] Complexity metrics within targets
- [ ] No unnecessary abstractions
- [ ] Code understandable to future self
- [ ] Documentation explains non-obvious decisions

**Architecture quality (code-architect.md):**
- [ ] Component responsibilities clear
- [ ] Data flow documented
- [ ] ADRs written for major decisions
- [ ] System boundaries defined

**Verification completeness (verify-app.md):**
- [ ] Core functionality tested
- [ ] Edge cases identified (even if not handled)
- [ ] Performance acceptable for educational use
- [ ] No critical bugs

**Build quality (build-validator.md):**
- [ ] Project builds successfully
- [ ] Dependencies documented
- [ ] Build script/instructions provided
- [ ] Can be rebuilt after time away

## Tier Completion Criteria

**Tier complete when:**
- All projects in tier completed per criteria above
- Concepts understood, not just code written
- Can explain each project to others
- Ready to apply concepts in next tier

**Tier review checklist:**
```
Tier [N]: [Name]

Projects completed: [X/Y]
Incomplete projects: [List]

Key concepts mastered:
- [ ] [Concept 1]
- [ ] [Concept 2]
- [ ] [Concept 3]

Projects enabled in next tier:
- Project [A] now unblocked
- Project [B] now unblocked

Reflection:
- Time spent: [Estimate]
- Most challenging: [Project]
- Best learning: [Insight]
- Would recommend: [Changes to approach]

Ready for Tier [N+1]: [YES | NO | PARTIAL]
```

## Progress Tracking

**Overall curriculum tracking:**
```
Total projects: 60
Completed: [X]
In progress: [Y]
Blocked: [Z]

Current tier: [N]
Estimated completion: [Date based on pace]

Dependency status:
- OS path: [Project N of M]
- Compiler path: [Project N of M]
- Network path: [Project N of M]
- Container path: [Project N of M]
- Browser path: [Project N of M]

Skills acquired:
- [Skill from completed projects]
- [Skill from completed projects]
```

# Time Management and Pacing

## Realistic Timeline Expectations

**Per tier estimates:**
- Tier 1 (8 projects): 1-2 months (1-2 weeks per project)
- Tier 2 (7 projects): 3-4 months (2-3 weeks per project)
- Tier 3 (6 projects): 3-4 months (2-3 weeks per project)
- Tier 4 (9 projects): 3-4 months (1.5-2 weeks per project)
- Tier 5 (4 projects): 2-3 months (2-3 weeks per project)
- Tier 6 (5 projects): 3-4 months (2-4 weeks per project)
- Tier 7 (6 projects): 4-5 months (3-4 weeks per project)
- Tier 8 (5 projects): 3-4 months (2-3 weeks per project)
- Tier 9 (5 projects): 4-5 months (3-4 weeks per project)
- Tier 10 (4 projects): 3-4 months (3-4 weeks per project)
- Tier 11 (1 project): 3-4 months

**Total: 3.5-4 years**

**Pacing guidelines:**
- Do not rush to "complete" without understanding
- Better to spend extra time on foundation (Tiers 1-2)
- Some projects will take longer than estimated
- Some projects will be faster if prerequisites solid
- Parallel learning (reading, courses) acceptable during longer projects

## Burnout Prevention

**From oncall-guide.md mental health principles:**
- Take breaks between major projects
- Celebrate tier completions
- If stuck >1 week, seek help or defer
- Feeling overwhelmed: revisit prerequisites
- Not a race: depth > speed

**Healthy pacing:**
- Maximum 1 complex project at a time
- Minimum 1-2 days break between projects
- Review previous projects monthly
- Document struggles and breakthroughs

# Integration with Other Configuration Files

## Architecture Integration (code-architect.md)

**For every project:**
1. Write ADR for technology choices
2. Define component structure
3. Document data flow
4. Specify integration points
5. Plan deployment model (local, web demo, etc.)

**ADR template for educational projects:**
```
# ADR-[PROJECT-NUMBER]: [Project Name] Architecture

## Status
Accepted

## Educational Context
Learning objectives: [What concepts this teaches]
Prior knowledge: [What projects/concepts prerequisite]

## Decision
[Architectural approach chosen]

## Educational Consequences
- Demonstrates: [Concepts shown]
- Simplifications: [What production systems do differently]
- Trade-offs: [Complexity vs educational clarity]

## Alternatives Considered
- [Production approach]: Too complex for educational setting
- [Simpler approach]: Doesn't demonstrate core concepts

## Verification Strategy
[How to know educational objectives met - reference verify-app.md]
```

## Simplification Integration (code-simplifier.md)

**Educational simplification principles:**
- Prefer clarity over performance
- Prefer straightforward over clever
- Prefer explicit over implicit
- Limit features to core concepts

**Acceptable complexity increases:**
- When demonstrating the concept being taught
- When avoiding abstraction would obscure learning
- When industry-standard pattern being learned

**Example:**
```
Project: Compiler
Educational complexity acceptable:
- Recursive descent parser (clear structure)
- Simple register allocation (demonstrates concept)

Educational complexity rejected:
- Advanced optimization passes (beyond scope)
- Complex error recovery (not core concept)
```

## Verification Integration (verify-app.md)

**Project-specific verification:**
- Functional: Does it work for core use cases?
- Educational: Did I learn the concepts?
- Quality: Is code understandable in 6 months?
- Integration: Do dependent projects work?

**Verification report per project:**
```
# Project [N] Verification Report

## Functional Verification
- [ ] Core features work
- [ ] Can demonstrate to others
- [ ] Handles basic inputs
- [ ] Fails gracefully on invalid input

## Educational Verification
- [ ] Can explain architecture
- [ ] Understand trade-offs made
- [ ] Can extend with new features
- [ ] Can debug issues

## Quality Verification
- [ ] Code complexity within targets (code-simplifier.md)
- [ ] Architecture documented (code-architect.md)
- [ ] Build reproducible (build-validator.md)
- [ ] No critical bugs

## Integration Verification
- [ ] Dependent projects still work
- [ ] Enables next tier projects
- [ ] Can be used as foundation

Decision: [COMPLETE | NEEDS_WORK]
Issues: [List]
```

## Build Validation Integration (build-validator.md)

**Per-project build validation:**
```
# Project [N] Build Validation

Environment:
- [ ] Compiler/interpreter installed
- [ ] Dependencies available
- [ ] Build tools present

Build:
- [ ] Builds without errors
- [ ] Builds in clean environment
- [ ] Build time acceptable (<5 min for educational projects)

Runtime:
- [ ] Runs successfully
- [ ] No immediate crashes
- [ ] Can execute test cases

Documentation:
- [ ] Build instructions present
- [ ] Dependencies listed
- [ ] Known issues documented
```

## Web Demo Integration (web-app-builder.md)

**For projects with web demos:**
- Follow web-app-builder.md artifact standards
- Use React for complex state visualization
- Provide interactive learning experience
- Document how demo simplifies/differs from real implementation

**Web demo project checklist:**
```
- [ ] Core concept visualized
- [ ] Interactive controls provided
- [ ] State changes visible
- [ ] Educational annotations included
- [ ] Responsive design (mobile learners)
- [ ] Performance acceptable in browser
- [ ] Accessibility for screen readers
```

# Output Standards

## Project Documentation Template

**Required for each project:**
```
# Project [N]: [Name]

## Overview
Tier: [N]
Duration: [Actual time spent]
Dependencies: [Projects required]
Enables: [Projects unblocked]

## Educational Objectives
- [Concept 1 learned]
- [Concept 2 learned]
- [Skill acquired]

## Architecture (code-architect.md)
Components:
- [Component 1]: [Responsibility]
- [Component 2]: [Responsibility]

Data flow:
[Description or diagram]

ADRs:
- ADR-[N]-1: [Major decision]
- ADR-[N]-2: [Major decision]

## Implementation Notes
Key files:
- [File]: [Purpose]
- [File]: [Purpose]

Complexity metrics (code-simplifier.md):
- Cyclomatic: [Max value]
- Functions: [Count]
- Lines of code: [Total]

Challenges:
- [Challenge and solution]

## Verification (verify-app.md)
Tested scenarios:
- [Test case 1]
- [Test case 2]

Known limitations:
- [Limitation 1]

## Integration
Used by:
- Project [M]: [How used]

Integrates with:
- Project [K]: [Integration point]

## Reflection
What went well:
- [Success]

What was difficult:
- [Difficulty]

Would do differently:
- [Change]

Time estimate vs actual:
- Estimated: [Time]
- Actual: [Time]
- Variance reason: [Explanation]

## Resources Used
- [Book/article]: [What learned]
- [Tutorial]: [What implemented]
- [Documentation]: [Reference]
```

## Tier Summary Documentation

**Required at tier completion:**
```
# Tier [N] Summary: [Name]

Duration: [Start date] - [End date] ([Total weeks])

## Projects Completed
1. [Project name] - [Key learning]
2. [Project name] - [Key learning]
...

## Skills Acquired
- [Skill 1]
- [Skill 2]
- [Skill 3]

## Key Concepts Mastered
- [Concept 1]: [Evidence of mastery]
- [Concept 2]: [Evidence of mastery]

## Architecture Patterns Learned
- [Pattern 1]: [Where applied]
- [Pattern 2]: [Where applied]

## Challenges Overcome
- [Challenge]: [How solved]

## Next Tier Preparation
Ready for Tier [N+1]: [YES/NO]

If NO, gaps:
- [Gap to address]

If YES, excited about:
- [Project to tackle]

## Recommendations for Others
- Start with: [Advice]
- Watch out for: [Warning]
- Helpful resources: [List]
```

# Constraints and Prohibitions

## Project Scope Constraints

**Never:**
- Build production-grade implementations (defeats educational purpose)
- Skip prerequisite projects (breaks dependency chain)
- Overengineer educational projects (violates code-simplifier.md)
- Ignore complexity metrics (defeats learning clarity)
- Rush through without understanding (defeats purpose)

**Always:**
- Verify prerequisites before starting
- Document architecture decisions
- Measure complexity
- Test core functionality
- Reflect on learning

## Simplification Constraints (code-simplifier.md)

**Educational projects must:**
- Prioritize clarity over completeness
- Limit features to core concepts
- Avoid production patterns that obscure learning
- Document where simplifications made
- Note differences from production implementations

**Example prohibitions:**
- No complex optimization passes in first compiler
- No advanced error recovery in first parser
- No production-grade concurrency in first OS
- No full HTML5 spec in first browser

## Progression Constraints

**Tier progression:**
- Cannot skip tiers (dependencies break)
- Cannot skip projects within critical paths
- Can parallelize independent paths (e.g., Tier 8 with Tier 7)
- Cannot proceed if prerequisites failed verification

**Dependency enforcement:**
- Memory allocator required before OS kernel
- Scripting language required before compiler
- CPU emulator required before VM
- File system required before container runtime
- Parser required before compiler

## Time Constraints

**Realistic expectations:**
- Minimum 3.5 years for full curriculum
- Most projects take longer than estimated initially
- Some projects require prerequisite knowledge acquisition
- Breaks and consolidation time required

**Prohibited approaches:**
- Rushing to "complete" curriculum in <2 years
- Skipping learning to hit timeline
- Counting "done" without verification
- Moving forward with critical gaps

# Verification Criteria

## Project Completion Criteria

**Project verified complete when:**
- All educational objectives documented as achieved
- Core functionality demonstrable
- Code quality within targets (code-simplifier.md)
- Architecture documented (code-architect.md)
- Build validated (build-validator.md)
- Integration tested (verify-app.md)
- Can explain to others
- Enables dependent projects

## Tier Completion Criteria

**Tier verified complete when:**
- All tier projects verified complete
- Concepts from tier mastered
- Can apply concepts without reference
- Tier summary documented
- Next tier prerequisites satisfied
- Ready to proceed confirmed

## Curriculum Completion Criteria

**Full curriculum complete when:**
- All 60 projects verified complete
- All 11 tiers verified complete
- Can explain systems engineering concepts
- Can architect new systems
- Can evaluate trade-offs
- Portfolio of working projects available

## Mastery Indicators

**Evidence of mastery:**
- Can build similar systems without guidance
- Can explain trade-offs to others
- Can extend projects with new features
- Can debug issues independently
- Can evaluate alternative approaches
- Can teach concepts to others
