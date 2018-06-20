import requests
import time

class Sat():

    def __init__(self, name, tle1, tle2):
        self.name = name
        self.tle1 = tle1
        self.tle2 = tle2
        self.num = tle1[2:7]

    def gen_sat_file(self):
        dest = '/home/technician/.config/Gpredict/satdata/' + self.num + '.sat'
        f = open(dest, "w")
        line1 = '[Satellite]' + '\n'
        line2 = 'VERSION=1.0' + '\n'
        line3 = 'NAME=' + self.name + '\n'
        line4 = 'NICKNAME=' + self.name + '\n'
        line5 = 'TLE1=' + self.tle1 + '\n'
        line6 = 'TLE2=' + self.tle2
        f.write(line1)
        f.write(line2)
        f.write(line3)
        f.write(line4)
        f.write(line5)
        f.write(line6)
        f.close()

def valid_date(start, end):
    localtime = time.localtime(time.time())
    year_now = localtime[0]
    month_now = localtime[1]
    day_now = localtime[2]
    start = start.split('/')
    end = end.split('/')
    now = localtime[0] + localtime[1] / 100.0 + localtime[2] / 10000.0
    start = float(start[2].strip()) + float(start[0]) / 100.0 + float(start[1]) / 10000.0
    end = float(end[2].strip()) + float(end[0]) / 100.0 + float(end[1]) / 10000.0
    if (start <= now) and (now <= end):
        return 1
    else:
        return 0

def valid_user(user):
    reg_users = ['matt.poole1@gmail.com']
    if user in reg_users:
        return 1
    else:
        return 0
    

def download_file_from_google_drive(key, destination):
    URL = "https://spreadsheets.google.com/feeds/download/spreadsheets/Export?"
    session = requests.Session()

    response = session.get(URL, params = { 'key' : key, 'exportFormat' : 'csv' }, stream = True)
    token = get_confirm_token(response)
    if token:
        params = { 'key' : key, 'confirm' : token }
        response = session.get(URL, params = params, stream = True)

    save_response_content(response, destination)

def get_confirm_token(response):
    for key, value in response.cookies.items():
        if key.startswith('download_warning'):
            return value
    return None

def save_response_content(response, destination):
    CHUNK_SIZE = 32768

    with open(destination, "wb") as f:
        for chunk in response.iter_content(CHUNK_SIZE):
            if chunk:
                f.write(chunk)

def parse_response(filename):
    
    f = open(filename, "r")
    lines = f.readlines()
    lines = lines[1:]
    sats = []
    for i in range(0, len(lines)):
        sat = []
        line = lines[i]
        line = line.split(',')
        user = line[6].strip()
        name = line[1]
        start = line[4]
        end = line[5]
        tle1 = line[2]
        tle2 = line[3]
        if valid_date(start, end) and valid_user(user):
            sat = Sat(name, tle1, tle2)
            sats.append(sat)
    return sats

def gen_mod(sats, name):
    line1 = '[GLOBAL]\n'
    line2 = 'SATELLITES='
    for sat in sats:
        line2 += sat.num + ';'
    line2 = line2[:-1]
    line2 += '\n'
    line3 = 'QTHFILE=AwaruaGroundStation.qth'
    f = open("/home/technician/.config/Gpredict/modules/" + name + ".mod", "w")
    f.write(line1)
    f.write(line2)
    f.write(line3)
    f.close()
        

if __name__ == "__main__":

    destination = '/home/technician/.config/responses.csv'
    module_name = "academic"
    file_id = '1qMQA6dLNQf8ohcW5uPgZ4Xq3mTxwW48MKk_bi6w5GpM'

    while True:    
    
        download_file_from_google_drive(file_id, destination)
        sats = parse_response(destination)
 
        for i in range(0, len(sats)):
            sat = sats[i]
            sat.gen_sat_file()
        gen_mod(sats, module_name)

        time.sleep(43200)

    

