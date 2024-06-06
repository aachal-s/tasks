import requests
import time

#define the API endpoint for fetching shared data
API_ENDPOINT = 'http://localhost:8080/api/shared_data'

#fetch shared data from Script B via API call
def fetch_shared_data():
    try:
        response = requests.get(API_ENDPOINT)
        if response.status_code == 200:
            return response.json()
        else:
            print(f'Failed to fetch shared data: {response.text}')
    except Exception as e:
        print(f'Error fetching shared data: {str(e)}')
    return None

def main():
    loop_frequency = 10  #10Hz
    while True:
        shared_data = fetch_shared_data()
        if shared_data:
            print(f'Fetched Counter: {shared_data["counter"]}, Timestamp: {shared_data["timestamp"]}')
        time.sleep(1.0 / loop_frequency)

if __name__ == '__main__':
    main()
