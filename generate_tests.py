import yaml
import subprocess

# === Load the structured YAML prompt ===
with open("prompts/student_prompt.yaml", "r") as f:
    prompt_config = yaml.safe_load(f)

# === Load the initial human-readable prompt ===
with open("prompts/initial_prompt.txt", "r") as f:
    initial_prompt = f.read()

# === Load the C++ source code ===
with open("src/student.cpp", "r") as f:
    cpp_code = f.read()

# === Combine all parts into the final prompt ===
final_prompt = initial_prompt + "\n\n"

# Inject YAML elements (optional but improves clarity)
if "test_format" in prompt_config:
    final_prompt += f"Test Framework: {prompt_config['test_format']}\n"

if "min_coverage" in prompt_config:
    final_prompt += f"Minimum coverage: {prompt_config['min_coverage']}\n"

if "include_libraries" in prompt_config:
    libs = ", ".join(prompt_config["include_libraries"])
    final_prompt += f"Required libraries: {libs}\n"

if "output_structure" in prompt_config:
    final_prompt += f"Test structure: {prompt_config['output_structure']}\n"

final_prompt += "\n---\nC++ Source Code:\n" + cpp_code

# === Run the LLM locally using Ollama + Deepseek Coder ===
print("[*] Generating test using deepseek-coder...")
ollama_command = ["ollama", "run", "deepseek-coder"]

process = subprocess.Popen(ollama_command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
output, error = process.communicate(final_prompt)

if error:
    print("[!] Error:", error)
else:
    # Save the result to test_student.cpp
    output_path = "tests/test_student.cpp"
    with open(output_path, "w") as f:
        f.write(output)

    print(f"[✅] Test generated and saved to {output_path}")
