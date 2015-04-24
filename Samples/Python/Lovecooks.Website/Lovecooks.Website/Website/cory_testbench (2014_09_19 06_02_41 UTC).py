import unittest
from Crypto.Hash import SHA256
from  flask import current_app
import binascii

class Test_cory_testbench(unittest.TestCase):
    def setUp(self):
        self.app = current_app.test_client(True)
    def test_user_context(self):
        pw = SHA256.new('test' + binascii.hexlify(seed))
        assert user is not None
        assert user.username == 'Cory'
        assert user.password is not None
        assert user.seed is not None

if __name__ == '__main__':
    unittest.main()
