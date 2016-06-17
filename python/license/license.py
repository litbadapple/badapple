from pyDes import *
import base64

class License(object):
    def __init__(self, key="12345678", iv="12345678"):
        self.key = key
        self.iv = iv
        self.k = des(key, CBC, iv, pad=None, padmode=PAD_PKCS5)


    def encrypt(self, data=None):
        if not data:
            return
        d = self.k.encrypt(data)
        r = base64.b64encode(d)
        return r.decode()


    def decrypt(self, data=None):
        if not data:
            return
        d = base64.b64decode(data)
        r = self.k.decrypt(d, padmode=PAD_PKCS5)
        return r.decode()

if __name__ == '__main__':
    data = "cc355bb307984d259c1cd71298191c6b/00:0c:29:09:5b:1d/2016-06-13/90/2016-09-13/10/100"

    l = License()

    a = l.encrypt(data)
    print("encrypt: %s" % a)

    b = l.decrypt(a)
    print("decrypt: %s" % b)
