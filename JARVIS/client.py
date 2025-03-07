from openai import OpenAI
 
# pip install openai 
# if you saved the key under a different environment variable name, you can do something like:
client = OpenAI(
  api_key="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",
)

completion = client.chat.completions.create(
  model="gpt-3.5-turbo",
  messages=[
    {"role": "system", "content": "You are a virtual assistant named jarvis skilled in general tasks like Alexa and Google Cloud"},
    {"role": "user", "content": "what is coding"}
  ]
)

print(completion.choices[0].message.content)