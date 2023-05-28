from flask import Flask, request

app = Flask(__name__)

# Sample translation function (replace with your actual translation logic)
def translate_text(text, source_language, target_language):
    translations = {
        'en-es': {
            'Hello': 'Hola',
            'How': 'Cómo',
            'Are': 'Estás',
            'You': 'Tú'
        },
        'es-en': {
            'Hola': 'Hello',
            'Cómo': 'How',
            'Estás': 'Are',
            'Tú': 'You'
        }
        # Add more translations as needed
    }
    
    translation_key = f'{source_language}-{target_language}'
    translation_dict = translations.get(translation_key, {})
    
    translated_text = []
    most_used_word = ''
    most_used_word_count = 0
    
    words = text.split()
    for word in words:
        translated_word = translation_dict.get(word, word)
        translated_text.append(translated_word)
        
        # Track the most used word
        word_count = words.count(word)
        if word_count > most_used_word_count:
            most_used_word = word
            most_used_word_count = word_count
    
    return {
        'source_text': text,
        'translated_text': ' '.join(translated_text),
        'most_used_word': most_used_word,
        'most_used_word_translation': translation_dict.get(most_used_word, most_used_word)
    }

@app.route('/translate', methods=['POST'])
def translate():
    """
    Endpoint for translating text from source language to target language.
    Expects a JSON payload with 'text', 'source_language', and 'target_language' parameters.
    Returns the translated text and the most used word with its translation.
    """
    data = request.get_json()
    text = data['text']
    source_language = data['source_language']
    target_language = data['target_language']
    
    translated_data = translate_text(text, source_language, target_language)
    
    return translated_data

@app.route('/languages', methods=['GET'])
def get_languages():
    """
    Endpoint for retrieving the list of supported languages.
    Returns a dictionary where keys are language codes and values are language names.
    """
    languages = {
        'en': 'English',
        'es': 'Spanish'
        # Add more languages as needed
    }
    return {
        'languages': languages
    }

if __name__ == '__main__':
    app.run()
