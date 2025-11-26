# ⚡ LLM → C++ Auto-Optimization Benchmark  
### *Accelerating Python to C++ using GPT‑5, Claude Opus 4.5 & Gemini 2.5 Pro via LiteLLM*

---

## 📘 Overview  
This project benchmarks **three LLMs generating optimized C++** from a Python numerical workload.  
The models receive identical system prompts and are evaluated on:

- 🔥 **Execution Speed vs Python**
- 🏎️ **LLM → C++ code compilation success**
- ⏱️ **LLM generation latency**
- 💰 **Cost per code‑generation request**

The target script computes π using a convergent series with **100 million iterations**, testing raw numerical throughput.

---

## 🎯 Objective

1. Convert Python into **high‑performance C++** automatically using LLMs.  
2. Compile and execute the generated C++ and benchmark speedup.  
3. Compare OpenAI, Anthropic and Google models on speed, cost, stability, and latency.

---

## 🧪 Experiment Setup

### Models used
| Key | Model |
|---|---|
| `gpt` | GPT‑5 (OpenAI) |
| `claude` | Claude Opus 4.5 (Anthropic) |
| `gemini` | Gemini 2.5 Pro (Google) |

### System Enforcement Rules  
All models must output pure C++17:

- No `<bits/stdc++.h>`  
- No Markdown or fenced code  
- No OpenMP / pragmas  
- Must compile with clang on **macOS Apple Silicon**

---

## ⚙️ Run the Benchmark

```bash
python run.py
```

or inside notebook:

```python
run_for_model_or_all("all", pi, repeats=1)
```

Requires `.env`:

```
OPENAI_API_KEY=...
ANTHROPIC_API_KEY=...
GEMINI_API_KEY=...
```

`LiteLLM` handles routing + cost tracking.

---

## 🔥 Results

### Python Baseline
```
Result = 3.141592658589
Execution Time = 19.011948s
```

### LLM‑Generated C++ Performance

| Model | Status | Cost ($) | LLM Latency (s) | C++ Runtime (s) | Speedup vs Python |
|---|---|---:|---:|---:|---:|
| GPT‑5 | ok | **0.014804** | 26.002 | **0.284435** | **66.84× faster** |
| Claude 4.5 Opus | ok | 0.043485 | **23.729** | 0.313464 | 60.65× faster |
| Gemini 2.5 Pro | ok | 0.088894 | 73.262 | **0.302568** | 62.84× faster |

---

## 📈 Interpretation & Takeaways

| Model | Best For | Notes |
|---|---|---|
| GPT‑5 | Peak speed + cost efficiency | Best overall speedup‑per‑dollar |
| Claude Opus | Low latency | Fastest LLM response time |
| Gemini 2.5 Pro | Strong output consistency | Slowest LLM latency but still top‑tier C++ speed |

### Summary
- All models generated **valid C++17** and executed successfully.  
- Final C++ binaries ran **60–67× faster than Python**.  
- LLM latency dominates total wall‑time (code generation ≫ execution cost).  
- GPT provided the **cheapest + fastest compiled result**, but Claude responded quicker.  

---

## 🚀 Next Steps

| Extension | Status |
|---|---|
| Multi‑threaded C++ experiments | 🔜 |
| Prompt optimization for vectorization | 🔜 |
| Add cost‑per‑speedup metric | 🔜 |
| Try open‑source models (Qwen, DeepSeek) | 🔜 |

---

## 🏁 Author  
Khashayar Bayati, PhD  
GitHub: **github.com/Khashayarbayati1**

