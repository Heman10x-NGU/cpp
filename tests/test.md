EDUCATION

DELHI TECHNOLOGICAL UNI-
VERSITY (DELHI COLLEGE OF

ENGINEERING)
B.Tech in Computer Science
2020 – 2024 | Delhi, India
CGPA: 8.46 / 10.0
LINKS
LinkedIn: heman10x
GitHub: Heman10x-NGU
LeetCode: Heman10x
TECHNICAL SKILLS
LANGUAGES
Python • Java • Golang
JavaScript • TypeScript • C++
FRAMEWORKS
Django • HTML CSS
Spring Boot • React.js • Node.js •
Express.js
TOOLS & INFRASTRUCTURE
Kafka • Docker • Git • CI/CD •
WebSockets • Distributed Systems •
gRPC • Redis • etcd • Observability•
Prometheus • Grafana • GenAI •
RESTful APIs • Microservices • Root
Cause Analysis (RCA) • Architecture •
Analytics
DATABASES
MongoDB • PostgreSQL • MySQL
AI/ML
LLM Integration • Groq • Instructor
Deepgram • Structured Outputs • AI
Agentic Integration
ACHIEVEMENTS
622 Problems - LeetCode (DSA)
AIR 5,968 - JEE Mains 2020 (Top 0.5%)
1st Place - BITS Pilani Hackathon ($5k)
1st Rank - Web 3.0 Track, HACK GDSC
2.0
Rank 599 - LeetCode Weekly Contest
473

WORK EXPERIENCE
BANK OF NEW YORK MELLON | Software Engineer
July 2024 – Present | Pune, India
• Implemented Spring Boot CompletableFuture-based collateral optimization
engine used by top-5 systematic HFT firms including leading market makers
and quantitative funds, with 4-stage pipeline handling 100+ fund
optimizations daily across $50B+ AUM achieving 97% success rate.
• Developed IBM MQ integration fortrade/transfer operations with dual
ACK/NACK processing and parent-child transaction orchestration, handling
50K+ daily messages with automated retry mechanisms and dead-letter queue
management.
• Built Universal Client Management sync service serving tier-1 institutional
prime brokerage clients, orchestrating 4-step API integration with exponential
backoffretries and batch processing, synchronizing 500+ client hierarchies
across multiple regions with comprehensive errorlogging.
• Optimized real-time financial dashboard APIs powering high-frequency
algorithmic trading workflows, aggregating earnings and allocation metrics
across $50B+ AUM,reducing API latency from 500ms to ~80ms through JPA
query optimization, Redis caching, and database indexing strategies.
• Deployed scheduled data sync services integrating external financial APIs with
region-aware business date handling, multithreaded processing, and
automated failure alerting for 2M+ daily records supporting quantitative
trading operations.
PROJECTS
PHRONAI | Voice-to-Architecture AI Agent
Python, Django, Pydantic, React, Groq, Deepgram | GitHub | Live Link
• Architected real-time AI agent using Django Channels (ASGI) and WebSockets
processing streaming audio with sub-3-second end-to-end latency from voice
input to rendered system architecture diagrams
• Integrated schema-validated LLM actions using Pydantic + Instructor(Groq
LLaMA),rejecting/repairing invalid generations before execution to achieve
near-100% valid structured outputs in testing.
• Built streaming speech-to-text integration with Deepgram Nova-2 API
achieving 300ms transcription latency with real-time audio chunk processing
over WebSocket connections
• Designed event-driven backend architecture with Django Channels and Redis
channel layers handling concurrent WebSocket sessions with automatic
message routing and session management
• Deployed on Render(Daphne/ASGI) with Supabase Auth + Upstash Redis;
added health checks and basic uptime monitoring, achieving near-99%
availability during monitored active-user periods on free-tier hosting.
NEXUSCACHE | Distributed Caching System
Go, etcd, gRPC, Docker, Prometheus, Grafana | GitHub
• Architected distributed cache achieving 23K+ ops/sec with sub-ms P50
latency (713μs) across 3-node cluster using consistent hashing (50 virtual
nodes) and LRU eviction.
• Used singleflight package to prevent thundering herd problem, deduplicating
concurrentrequests foridentical keys into single database calls.
• Configured automatic service discovery using etcd with lease-based health
checks (10s TTL) enabling dynamic node registration and automatic failover.
• Designed gRPC inter-node communication with Protocol Buffers; integrated
Prometheus/Grafana exposing real-time p50/p95/p99 latencies and cache hit
rates.
