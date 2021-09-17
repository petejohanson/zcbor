/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>
#include "pet_decode.h"
#include "serial_recovery_decode.h"
#include "cbor_debug.h" // Enables use of print functions when debugging tests.

uint8_t serial_rec_input1[] = {
	/* "data" */
	0xa5, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01,
	0x29, 0x3d, 0xb8, 0xf3, 0x96, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0xdc, 0x37, 0x00,

	/* 280 zeros */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, /* "image" */ 0x65, 0x69, 0x6d, 0x61, 0x67, 0x65,
	0x00, /* "len" */ 0x63, 0x6c, 0x65, 0x6e, 0x19, 0x3b, 0x2c,
	/* "off" */ 0x63, 0x6f, 0x66, 0x66, 0x00, /* "sha" */ 0x63, 0x73, 0x68,
	0x61, 0x58, 0x20, 0x12, 0x87, 0x4f, 0xfe, 0x60,
	0x5b, 0xe0, 0x63, 0x1a, 0x03, 0x5a, 0xa2, 0x11,
	0xb4, 0x3e, 0x0f, 0xb0, 0x20, 0x42, 0x0f, 0xc4,
	0x31, 0xa7, 0xf1, 0x1a, 0x6a, 0xd3, 0x44, 0x4c,
	0x71, 0x99, 0x75
};


uint8_t serial_rec_input2[] = {
	/* "data" */
	0xa5, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01,
	0x29, 0x3d, 0xb8, 0xf3, 0x96, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x90, 0x2c, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01,

	/* 11 zeros */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,

	/* 265 0xffs */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff,

	/* "image" */
	0x65, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x00, /* "len" */ 0x63,
	0x6c, 0x65, 0x6e, 0x19, 0x2f, 0xe0, /* "off" */ 0x63, 0x6f,
	0x66, 0x66, 0x00, /* "sha" */ 0x63, 0x73, 0x68, 0x61, 0x58,
	0x20, 0x1d, 0x4f, 0x47, 0xe6, 0xdf, 0x78, 0xad,
	0x34, 0xe2, 0xd2, 0x8f, 0xc6, 0x7b, 0x3f, 0x26,
	0xff, 0x3c, 0x73, 0x44, 0x93, 0x13, 0x32, 0x7b,
	0x27, 0x15, 0xfa, 0x1d, 0x6e, 0x21, 0x82, 0xcb,
	0xfb
};


/* This test uses generated code to decode a 'Pet' instance. It constructs a
 * payload and runs the generated decoding function on the payload. It then
 * checks that the decoding was successful, and that the resulting struct is
 * populated correctly.
 */
void test_pet(void)
{
	struct Pet pet;
	uint32_t decode_len;
	uint8_t input[] = {
		0x83, 0x82, 0x63, 0x66, 0x6f, 0x6f, 0x63, 0x62, 0x61, 0x72,
		0x48, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
		0x02};
	zassert_true(cbor_decode_Pet(input, sizeof(input), &pet, &decode_len), "");
	zassert_equal(sizeof(input), decode_len, NULL);

	uint8_t exp_birthday[] = {1,2,3,4,5,6,7,8};

	zassert_equal(2, pet._Pet_name_tstr_count, "Expect 2 names");
	zassert_mem_equal("foo", pet._Pet_name_tstr[0].value, 3, "Expect first name 'foo'");
	zassert_mem_equal("bar", pet._Pet_name_tstr[1].value, 3, "Expect first name 'bar'");
	zassert_equal(8, pet._Pet_birthday.len, "Expect len 8 birthday");
	zassert_mem_equal(exp_birthday, pet._Pet_birthday.value, 8, "Expect birthday");
	zassert_equal(_Pet_species_dog, pet._Pet_species_choice, "Expect dog");
}

void test_serial1(void)
{
	struct Upload upload;
	uint32_t decode_len;
	bool ret = cbor_decode_Upload(serial_rec_input1,
			sizeof(serial_rec_input1), &upload, &decode_len);
	zassert_true(ret, "decoding failed.");
	zassert_equal(sizeof(serial_rec_input1), decode_len, NULL);

	zassert_equal(5, upload._Upload_members_count,
		"expect 5 members");
	zassert_equal(_Member_data, upload._Upload_members[0]._Upload_members
		._Member_choice, "expect data 1st");
	zassert_equal(_Member_image, upload._Upload_members[1]._Upload_members
		._Member_choice, "expect image 2nd");
	zassert_equal(_Member_len, upload._Upload_members[2]._Upload_members
		._Member_choice, "expect len 3rd");
	zassert_equal(_Member_off, upload._Upload_members[3]._Upload_members
		._Member_choice, "expect off 4th");
	zassert_equal(_Member_sha, upload._Upload_members[4]._Upload_members
		._Member_choice, "expect sha 5th");
}

void test_serial2(void)
{
	struct Upload upload;
	uint32_t decode_len;
	bool ret = cbor_decode_Upload(serial_rec_input2,
			sizeof(serial_rec_input2), &upload, &decode_len);
	zassert_true(ret, "decoding failed.");
	zassert_equal(sizeof(serial_rec_input2), decode_len, NULL);

	zassert_equal(5, upload._Upload_members_count,
		"expect 5 members");
	zassert_equal(_Member_data, upload._Upload_members[0]._Upload_members
		._Member_choice, "expect data 1st");
	zassert_equal(_Member_image, upload._Upload_members[1]._Upload_members
		._Member_choice, "expect image 2nd");
	zassert_equal(_Member_len, upload._Upload_members[2]._Upload_members
		._Member_choice, "expect len 3rd");
	zassert_equal(_Member_off, upload._Upload_members[3]._Upload_members
		._Member_choice, "expect off 4th");
	zassert_equal(_Member_sha, upload._Upload_members[4]._Upload_members
		._Member_choice, "expect sha 5th");
}

void test_main(void)
{
	ztest_test_suite(cbor_decode_test3,
			 ztest_unit_test(test_pet),
			 ztest_unit_test(test_serial1),
			 ztest_unit_test(test_serial2)
	);
	ztest_run_test_suite(cbor_decode_test3);
}
